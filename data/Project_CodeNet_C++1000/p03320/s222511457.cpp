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
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;
const double pi=3.141592653589793;

ll sumofdigits(ll n){
    ll sum =0;
    while(n>0){
        sum += n%10;
        n /=10;
    }
    return sum;
}

double snuke(ll n){
    return (double)n/(double)sumofdigits(n);
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n,a=1;
    vll ans;
    cin>>n;
    rep(i,15){
        rep2(j,1,150){
            ans.pb(a*(j+1)-1);
        }
        a*=10;
    }
    sort(all(ans));
    ans.erase(unique(all(ans)),ans.end());
    ll s=ans.size();
    rep(i,s){
        rep2(j,i+1,s){
            if(snuke(ans[i])>snuke(ans[j])){
                ans.erase(ans.begin() + i--);
                break;
            }
        }
    }
    rep(i,n){
        cout<<ans[i]<<endl;
    }
    return 0;
}