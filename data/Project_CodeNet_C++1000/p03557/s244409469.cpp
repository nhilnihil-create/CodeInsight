//url:
//problem name: 

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N; cin >> N;
    vecl A(N),B(N),C(N);
    REP(i,N) cin >> A[i];
    REP(i,N) cin >> B[i];
    REP(i,N) cin >> C[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    /*
    for(int a : A) cout << a << " ";
    cout << endl;
    for(int a : B) cout << a << " ";
    cout << endl;
    for(int a : C) cout << a << " ";
    cout << endl;
    */
    ll ans = 0;
    REP(i,N) {
        ll b = B[i];
        ll l1 = -1;
        ll r1 = N;
        while(r1-l1 > 1) {
            ll mid = (l1+r1)/2;
            if(A[mid] >= b) r1 = mid;
            else l1 = mid;
        } 
        ll l2 = -1;
        ll r2 = N;
        while(r2-l2 > 1) {
            ll mid = (l2+r2)/2;
            if(C[mid] > b) r2 = mid;
            else l2 = mid;
        } 
        /*
        cout << l1 << " " << r1 << endl;
        cout << l2 << " " << r2 << endl;
        cout << endl;
        */
        ans += (l1+1)*(N-r2);
    }
    cout << ans << endl;
}
