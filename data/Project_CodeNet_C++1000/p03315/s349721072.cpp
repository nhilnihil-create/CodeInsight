#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
const ll M=1000000007;
//------------------------------------------//

int main(){
    char c;
    int ans=0;
    rep(i,4){
        cin>>c;
        if(c=='+') ans++;
        else ans--;
    }
    cout<<ans<<endl;
}
