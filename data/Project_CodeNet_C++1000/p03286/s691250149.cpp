#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long ,long long>pll;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return ((a*b)/gcd(a,b));}
bool cmp(int a,int b){return a>b;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

 long long modpow(long long n, long long k,long long mod)
{
if (k == 0) return 1;
long long r = modpow(n * n % mod, k >> 1, mod);
if (k & 1) r = r * n % mod;
return r;
}

void solve(){
     int n;cin >>  n;
     vector<int>a(55,0);
     bool ok = 1;int cnt = 0;
     if(n<0) ok = 0;
     n = abs(n);
     while(n){
        if(n%2) a[cnt]++;
        cnt++;
        n /= 2;
     }
     if(ok){
        for(int i = 0;i<50;i++){
            if(i%2&&a[i]) a[i+1]++;
        }
        for(int i = 0;i<50;i++)
        while(a[i]>=2){
            a[i] -= 2;
            if(a[i+1]>0) a[i+1]--;
            else {a[i+1]++;a[i+2]++;}
     }}
     else{
        for(int i = 0;i<50;i++){
            if(i%2==0&&a[i]) a[i+1]++;
        }
        for(int i = 0;i<50;i++)
        while(a[i]>=2){
            a[i] -= 2;
            if(a[i+1]>0) a[i+1]--;
            else {a[i+1]++;a[i+2]++;}
    }
}
     int pos = 0;
     for(int i = 50;i>=0;i--){
        if(a[i]>0){
            pos = i;break;
        }
     }
     for(int i = pos;i>=0;i--){
        cout << a[i];
     }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}