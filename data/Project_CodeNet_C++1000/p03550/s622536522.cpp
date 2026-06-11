#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
const int mod=998244353;
int main(){
    ll n,z,w;
    cin>>n>>z>>w;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    if(n==1){
        cout<<abs(a[0]-w)<<endl;
        return 0;
    }
    cout<<max(abs(a[n-1]-a[n-2]),abs(a[n-1]-w))<<endl;
}