#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n;  cin >> n;
    int u[n],d[n];
    rep(i,n){
        cin >> u[i];
    }
    rep(i, n){
        cin >> d[i];
    }

    int ans(0);
    rep(i,n){
        int sum(0);
        bool isUp(true);
        rep(j,n){
            if(isUp){
                if(i==j){
                    isUp = false;
                    sum += u[j]+d[j];
                }else{
                    sum += u[j];
                }
            }else{
                sum += d[j];
            }
        }
        ans = max(ans,sum);
    }

    cout << ans << endl;

    return 0;
}