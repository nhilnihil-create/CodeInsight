#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    int g;
    int wa;
    vector <vector <int>> ans(2);
    if(n%2==0){
        g=n/2;
        wa=n+1;
        rep(i,n){
            rep(j,n){
                if(i>=j){
                    continue;
                }
                else if(j==n-i-1){
                    continue;
                }
                else{
            ans[0].push_back(i+1);
            ans[1].push_back(j+1);
                }
        }
        }
        
    }
    else{
        --n;
        rep(i,n){
            rep(j,n){
                if(i>=j){
                    continue;
                }
                else if(j==n-i-1){
                    continue;
                }
                
                else{
            ans[0].push_back(i+1);
            ans[1].push_back(j+1);
                }
        }
        }
        rep(i,n){
            ans[0].push_back(i+1);
            ans[1].push_back(n+1);
        }
    }

    ll l;
    l=ans[0].size();
    cout << l << endl;
    rep(i,l){
        cout << ans[0][i] << " " << ans[1][i] << endl;
    }
    

    return 0;
}