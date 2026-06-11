#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int n,c;
    cin >> n >> c;
    int d[c][c];
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            cin >> d[i][j];
        }
    }
    int bd[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> bd[i][j];
        }
    }
    map<int,int> mp[3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mp[(i+j+2)%3][bd[i][j]]++;
        }
    }
    ll ans = mod*mod;
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            if(i == j) continue;
            for(int k = 0; k < c; k++){
                if(i == k || j == k) continue;
                ll can = 0;
                for(auto p : mp[0]){
                    can += p.second*d[p.first-1][i];
                }
                for(auto p : mp[1]){
                    can += p.second*d[p.first-1][j];
                }
                for(auto p : mp[2]){
                    can += p.second*d[p.first-1][k];
                }
                if(ans > can){
                    ans = can;
                    //cout << ans << endl;
                    //cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}