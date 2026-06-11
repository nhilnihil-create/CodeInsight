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
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;
ll dp[1001][1001];
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(0);
    for(int i=0;i<n;i++){
        ll now;
        cin>>now;
        a.push_back(now);
    }
    vector<P> cb(m);
    for(int i=0;i<m;i++){
        cin>>cb[i].second>>cb[i].first;
    }
    sort(cb.begin(),cb.end(),greater<P>());
    int f=n;
    int now=0;
    while(f && now<cb.size()){
        int c=cb[now].first;
        int b=cb[now].second;
        while(b>0 && f>0){
            a.push_back(c);
            b--; f--;
        }
        now++;
    }
    sort(a.begin(),a.end(),greater<ll>());
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i];
    }
    cout<<ans<<endl;

    
}