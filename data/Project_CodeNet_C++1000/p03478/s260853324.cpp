#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
    ll N,A,B;
    cin>>N>>A>>B;
    ll ans=0;
    rep(i,1,N+1){
        ll sum=0;
        string s=to_string(i);
        rep(j,0,s.size()){
            sum+=s[j]-'0';
        }
        if(A<=sum&&sum<=B)ans+=i;
    }
    cout << ans << endl;
    return 0;
}