#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL<<60;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP2(i,m,n) for(int i=m;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(){
    int n,h,w;
    cin >> n>> h>>w;
    int ans=0;
    REP(i,n){
        int a,b;
        cin >> a>>b;
       ans +=  min(a/h,b/w);
    }

    cout <<ans << endl;
}