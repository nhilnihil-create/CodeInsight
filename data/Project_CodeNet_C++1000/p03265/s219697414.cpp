#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REPS(i,n) for(ll (i)=1;(i)<=(n);(i)++)
#define RREP(i,n) for(ll (i)=(n-1);(i)>=0;(i)--)
#define RREPS(i,n) for(ll (i)=(n);(i)>0;(i)--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());

template<class T> inline void chmin(T& a, T b){
    if (a > b){
        a = b;
    }
}

template<class T> inline void chmax(T& a, T b){
    if (a < b){
        a = b;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<int> A = {x2-x1,y2-y1};
    swap(A[0],A[1]);
    A[0]*=-1;
    int x3,y3,x4,y4;
    x3 = x2 + A[0];
    y3 = y2 + A[1];
    swap(A[0],A[1]);
    A[0]*=-1;
    x4 = x3 + A[0];
    y4 = y3 + A[1];
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
}