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

int main(){
    int n;cin >> n;
    vector<int> a(n+2);
    a[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    a[n+1] = 0;
    int sum = 0;
    for(int i=1;i<n+2;i++){
        sum+=abs(a[i]-a[i-1]);
    }
    //debug(sum);
    for(int i=1;i<=n;i++){
        cout << sum-abs(a[i]-a[i-1])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1]) << newl;
    }
}
// 0 3 5 -1 0
//3+2+6+1

