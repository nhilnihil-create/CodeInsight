#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
#define sq(x) (x)*(x)
using namespace std;

// #define int double
// #define double long double
const int maxn = 1e2+3;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

const int B = 1024+20;

stack<int> have;

int n;
void go(int at){
    if (at==n) return;
    if (!have.size()){
        int og = at; while (at<n) cout<<og<<' '<<++at<<'\n';
        return;
    }
    int A = have.top(); have.pop();
    int og = at;
    while (at <= n-A){
        at++; cout<<og<<' '<<at<<'\n';
    }
    go(at);
}


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
     string s; cin>>s;
     n = s.length();
     if (s[n-1]=='1') GG();
     if (s[0]!='1') GG();
     REP(i, n-1) {
        if (s[i]!=s[n-i-2]) GG();
     }
     REP(i, (n+1)/2){
        if (s[i]=='1') have.push(i+1); // 1 based
     }

     go(1);
}