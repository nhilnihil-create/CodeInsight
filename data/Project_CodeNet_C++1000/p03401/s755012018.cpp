#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <stack>
#include <deque>
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl
#define isort(a) sort(a.begin(),a.end())
 
using namespace std;
 
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}
 
typedef pair<ll,ll> Pair;
const ll inf =1000000007;

void solve(){
    ll n;
    cin >> n;
    ll x[n+2];
    ll sum=0;
    x[0]=0;x[n+1]=0;
    rep(i,n){
        cin >> x[i+1];
        sum+=abs(x[i+1]-x[i]);
    }
  sum+=abs(x[n+1]-x[n]);
    rep(i,n){
        ll ans=sum;
        ans-=(abs(x[i+1]-x[i])+abs(x[i+2]-x[i+1])-abs(x[i+2]-x[i]));
        kaku(ans);
    }
}

int main(){
    solve();
}




//


