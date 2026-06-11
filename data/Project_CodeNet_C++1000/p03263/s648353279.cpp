#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w, 0));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    vector<int> ans;
    int cnt = 0;
    for(int i = 0; i < h; i++){
        if(i % 2 == 0){
            for(int j = 0; j < w; j++){
                if(i == h-1 && j == w-1) break;
                if(a[i][j]%2 != 0){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    a[i][j]--;
                    if(j == w-1){
                        ans.push_back(i+2);
                        ans.push_back(w);
                        a[i+1][w-1]++;
                    }
                    else{
                        ans.push_back(i+1);
                        ans.push_back(j+2);
                        a[i][j+1]++;
                    }
                    cnt++;
                }
            }
        }
        else{
            for(int j = w-1; j >= 0; j--){
                if(i == h-1 && j == 0) break;
                if(a[i][j]%2 != 0){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    a[i][j]--;
                    if(j == 0){
                        ans.push_back(i+2);
                        ans.push_back(1);
                        a[i+1][0]++;
                    }
                    else{
                        ans.push_back(i+1);
                        ans.push_back(j);
                        a[i][j-1]++;
                    }
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;

    for(int i = 0; i < cnt; i++){
        cout << ans[4*i] << ' ' << ans[4*i+1] << ' ' << ans[4*i+2] << ' ' << ans[4*i+3];
        cout << endl;
    }
}