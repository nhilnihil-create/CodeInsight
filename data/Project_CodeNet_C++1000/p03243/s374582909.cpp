#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;
 
int main(){
    ll N;
    cin>>N;
    ll ans;
    rep(i,1,10){
        if(N<=i*111){ans=i*111;break;}
        else continue;
    }
    cout<<ans<<endl;
    return 0;
}