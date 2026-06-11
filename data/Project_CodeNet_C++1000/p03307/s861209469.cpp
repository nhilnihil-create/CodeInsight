#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main(){
    ll N;
    cin>>N;
    ll ans=0;
    if(N%2==0)ans=N;
    else ans=2*N;
    cout<<ans;
    return 0;
}