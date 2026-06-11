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
    ll n,k;
    cin >> n >>k;
    if(k%2==1){
        ll ans=pow(n/k,3);
        cout << ans << endl;
    }
    else{
        ll ans=pow(n/k,3);
        if(n%k<k/2){
            ans+=pow(n/k,3);
        }
        else{
            ans+=pow(n/k+1,3);
        }
        cout << ans << endl;
    }
}

int main(){
    solve();
}

