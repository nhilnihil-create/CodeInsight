#include <iostream>
#include <string>

#define N 8000

using namespace std;

bool dp_x[2*N+1][8000] = {false};
bool dp_y[2*N+1][8000] = {false};

int main(){
    string S;
    int x, y;
    cin >> S;
    cin >> x >> y;
    int cnt_F = 0;
    int cnt_T = 0;
    int cnt_x = 0;
    int cnt_y = 0;
    bool first_F = true;
    for(int i = 0; i < 2*N+1; i++){
        for(int j = 0; j < N; j++){
            dp_x[i][j] = false;
            dp_y[i][j] = false;
        }
    }
    int cnt = 0;
    while(S[cnt] == 'F'){
        cnt++;
    }
    dp_x[cnt+N+1][0] = true;
    dp_y[N+1][0] = true;
    for(int i = cnt; i < S.size(); i++){
        if(S[i] == 'T' || i == S.size()-1){
            if(i == S.size()-1 && S[i] == 'F')cnt_F++;
            if(cnt_F != 0){
                if(cnt_T%2 == 0){
                    cnt_x++;
                    for(int i = 0; i < 2*N+1; i++){
                        if(dp_x[i][cnt_x-1]){
                            dp_x[i+cnt_F][cnt_x] = true;
                            dp_x[i-cnt_F][cnt_x] = true;
                        }
                    }
                }else{
                    cnt_y++;
                    for(int i = 0; i < 2*N+1; i++){
                        if(dp_y[i][cnt_y-1]){
                            dp_y[i+cnt_F][cnt_y] = true;
                            dp_y[i-cnt_F][cnt_y] = true;
                        }
                    }
                }
            }
            cnt_T++;
            cnt_F = 0;
        }
        else{
            cnt_F++;
        }
    }
    if(dp_x[x+N+1][cnt_x] && dp_y[y+N+1][cnt_y]) cout << "Yes" << endl;
    else cout << "No" << endl;
}