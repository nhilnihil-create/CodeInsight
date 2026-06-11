#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
 
ll MOD = 1000000007;
ll INF =1<<29;

int main() {
    int x;
    cin >> x;
    int M = 1;
    for(int i=2;i<=31;++i){
        int a = i;
        int cnt =0;
        while(a<=x){
        a*=i;
        cnt++;}
        if(cnt>=2){
        int ans =a/i;
        M = max(M,ans);} 
    }
    cout << M <<endl;
} 