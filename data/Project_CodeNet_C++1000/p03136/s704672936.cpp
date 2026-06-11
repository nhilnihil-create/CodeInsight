#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()


int main()
{
    ll N;  cin>>N;
    VL L(N);
    rep(i,0,N)cin>>L[i];
    
    sort(ALL(L));
    ll sum=0;
    rep(i,0,L.size()-1)sum+=L[i];
    
    if(L[L.size()-1]>=sum)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}