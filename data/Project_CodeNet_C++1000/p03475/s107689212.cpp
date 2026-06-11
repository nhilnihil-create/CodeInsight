#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
const char newl = '\n';
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 1LL<<60;

int N,c[500],s[500],f[500];
int main(){
    int n;
    cin >> n;
    rep(i,n-1) cin >> c[i] >> s[i] >> f[i];
    rep(i,n){
        int t=0;
        for(int j=i;j<n-1;j++){
            if(t<s[j]) t= s[j];
            else if(t%f[j]==0);
            else t= t+f[j]-t%f[j];
            t+=c[j];
        }
        cout << t << newl;
    }
}