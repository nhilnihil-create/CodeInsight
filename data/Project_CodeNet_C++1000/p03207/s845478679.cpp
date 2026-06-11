#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (ll i = (srt); i < (ll)(end); i++)

int main()
{
    ll N; cin>>N;
    vector<ll> p(N);
    rep(i,0,N)cin>>p[i];
    sort(p.begin(),p.end());

    ll sum=p[p.size()-1]/2;
    rep(i,0,N-1)sum+=p[i];
    
    cout<<sum<<endl;    
    return 0;
}