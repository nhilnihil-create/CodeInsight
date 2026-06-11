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
    ll n,m;
    cin >> n >>m;
    ll ans=0;
    ans+=(n-2)*(m-2);
  if(ans<0) ans=0;
    if(n==1 || m==1){
        ans+=max(n-2,m-2);
    }
    if(n==1 && m==1) ans=1;
    kaku(ans);
}

int main(){
    solve();
}




//


