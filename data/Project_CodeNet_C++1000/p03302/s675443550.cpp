#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
// #define int ll
using namespace std;
const int INF (1 << 30);
const ll LLINF (1LL << 55LL);
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll a,b;
    cin>>a>>b;
    if(a+b==15) cout<<"+"<<endl;
    else if(a*b==15) cout<<"*"<<endl;
    else cout<<"x"<<endl;
    return 0;
}