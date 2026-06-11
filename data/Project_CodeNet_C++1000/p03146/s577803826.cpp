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
    ll s;
    cin>>s;
    ll cnt=1;
    map<ll,ll> mp;
    mp[s]++;

    while(true){
        cnt++;
        if(s%2==0)s/=2;
        else s=3*s+1;
        
        if(mp[s])break;
        else mp[s]++;       
    }
    
    cout<<cnt<<endl;
    return 0;
}