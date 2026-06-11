#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int h,w;
    cin >> h >> w;
    int a[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }    
    vector<pair<int,int>> ans[2];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j]%2 == 1){
                if(i != h-1){
                    if(j+1 < w){
                        a[i][j]--;
                        a[i][j+1]++;
                        ans[0].push_back({i+1,j+1});
                        ans[1].push_back({i+1,j+2});
                    }
                    else{
                        a[i][j]--;
                        a[i+1][j]++;
                        ans[0].push_back({i+1,j+1});
                        ans[1].push_back({i+2,j+1});
                    }
                }
                else {
                    if(j+1 < w){
                        a[i][j]--;
                        a[i][j+1]++;
                        ans[0].push_back({i+1,j+1});
                        ans[1].push_back({i+1,j+2});
                    }
                }
            }
        }
    }
    cout << ans[0].size() << endl;
    for(int i = 0; i < ans[0].size(); i++){
        cout << ans[0][i].first << " " << ans[0][i].second << " ";
        cout << ans[1][i].first << " " << ans[1][i].second << endl;
    }
    return 0;
    
}