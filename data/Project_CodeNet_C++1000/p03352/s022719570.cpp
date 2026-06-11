#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int x;  cin >> x;

    if(x==1){
        cout << 1  << endl;
        return 0;
    }
    int ans(0);
    for(int i=1;i<=x;i++){
        for(int j=2;j<=x;j++){
            int t = pow(i,j);
            if(t>x){
                break;
            }else{
                ans = max(ans,t);
            }
        }
    }

    cout << ans << endl;

    return 0;
}