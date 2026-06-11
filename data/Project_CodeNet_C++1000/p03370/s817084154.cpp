#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n,x;
    cin >> n >> x;

    vector<int> v(n);
    int ans(0);
    rep(i,n){
        cin >> v[i];
        ans++;
        x -= v[i];
    }

    sort(v.begin(),v.end());

    if(v[0]<=x){
        while(1){
            x -= v[0];
            if(x<0){
                break;
            }
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}