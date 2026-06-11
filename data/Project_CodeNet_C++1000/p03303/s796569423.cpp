#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,n) for(int i=a;i<n;++i)
#define REPL(i,a,n) for(ll i=a;i<n;++i)
#define RUP(a,b) ((a+b-1)/(b))
#define ENT "\n"
#define SORTVG(v) sort(v.begin(),v.end(),greater<>())
#define SORTV(v) sort(v.begin(),v.end())
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define INF LLONG_MAX/2

typedef long long ll;
typedef tuple<int,int,bool> Tb;
typedef pair<int,int> Pii;
typedef vector<int> Vi;

template<class T> void chmax(T& a, T b) {if(a < b){a=b;}}
template<class T> void chmin(T& a, T b) {if(a > b){a=b;}}
template<class T> void YesNo(T& a) {if(a){cout << "Yes" << ENT;}else{cout << "No" << ENT;}}
template<class T> void YESNO(T& a) {if(a){cout << "YES" << ENT;}else{cout << "NO" << ENT;}}
template<class T> void AorB(T& a, string A,string B) {if(a){cout << A << ENT;}else{cout << B << ENT;}}

int atcoder(){
    string s;
    int n;
    cin>>s>>n;
    REP(i,0,RUP(s.length(),n)) cout<<s[0+n*i];
    cout<<ENT;
    return 0;
}


signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    atcoder();
    return 0;
}
