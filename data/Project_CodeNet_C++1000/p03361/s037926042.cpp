#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++) cin >> s[i];
    int dy[4] = {0,0,1,-1};
    int dx[4] = {-1,1,0,0};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#'){
                bool ok = false;
                for(int k = 0; k < 4; k++){    
                    if(0 <= dy[k]+i && dy[k]+i < h && 0 <= dx[k]+j && dx[k]+j < w){
                        int y = dy[k]+i;
                        int x = dx[k]+j;
                        if(s[y][x] == '#') ok = true;
                    }
                }
                if(!ok){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}