#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++) cin >> s[i];

    string ans = "Yes";
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '.') continue;
            bool isok = false;
            for(int k = 0; k < 4; k++){
                if(i+dx[k] >= 0 && i+dx[k] < h && j+dy[k] >= 0 && j+dy[k] < w){
                    if(s[i+dx[k]][j+dy[k]] == '#') isok = true;
                }
            }
            if(!isok) ans = "No";
        }
    }

    cout << ans << endl;
    return 0;
}