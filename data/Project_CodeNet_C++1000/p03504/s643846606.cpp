#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;


int main(){
    ll n,c;
    cin>>n>>c;
    vector<vector<ll> > s(c,vector<ll>(0)),t(c,vector<ll>(0));
    for(ll i=0;i<n;i++){
        ll s_,t_,c_;
        cin>>s_>>t_>>c_;
        s[c_-1].push_back(s_);
        t[c_-1].push_back(t_);
    }
    for(ll i=0;i<c;i++){
        sort(s[i].begin(),s[i].end());
        sort(t[i].begin(),t[i].end());
    }

    ll ans=0;
    for(ll time=0;time<100010;time++){
        ll sub=0;
        //cout<<"t="<<time<<endl;
        for(ll j=0;j<c;j++){
            sub+=min(upper_bound(s[j].begin(),s[j].end(),time)-s[j].begin()-(lower_bound(t[j].begin(),t[j].end(),time)-t[j].begin()),(long)1);
            //cout<<sub<<endl;
        }
        ans=max(sub,ans);
    }
    cout<<ans<<endl;

}