#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;

    vector <int> ans(100001);
    rep(i,100001){
        ans[i]=i;
    }

    int x6=1;
    int k;
    rep(i,6){
        x6*=6;
        k=x6;
        rep(j,100001){
            if(j<k){
                continue;
            }
            else{
            ans[j]=min(ans[j],ans[j-x6]+1);
            }
        }
    }

    int x9=1;
    //int k;
    rep(i,5){
        x9*=9;
        k=x9;
        rep(j,100001){
            if(j<k){
                continue;
            }
            else{
            ans[j]=min(ans[j],ans[j-x9]+1);
            }
        }
    }

    /*rep(i,100){
        cout << i << " " << ans[i] << endl;
    }*/

    cout << ans[n] << endl;
    

    return 0;
}