#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long

    int main (){
        int n,m,c;
        cin >> n >> m >> c;
        vector<int> b(m);
        vector<vector<int>>  a(n,vector<int>(m));
    rep(i,m){
        cin >> b[i];
    }

        rep(i,n){
            rep(j,m){
                cin >> a.at(i).at(j);
            }
        }

        int ans =0;

            rep(i,n){
                int sum=0;
                 rep(j,m){
                      sum += b.at(j)*a.at(i).at(j);
                    
                 } 
                 if(sum+c>0){
                     ans++;
                 }
        }
        cout << ans << endl;
        return 0;
    }