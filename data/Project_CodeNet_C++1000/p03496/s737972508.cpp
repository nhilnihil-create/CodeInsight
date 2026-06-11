#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using pint = pair<int,int>;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    int amax = -1e+6-10, amin = 1e+6+10;
    bool allpos = true, allneg = true;
    REP(i,N) {
        cin >> a[i];
        amax = max(amax,a[i]);
        amin = min(amin,a[i]);
        if ( a[i] < 0 ) allpos = false;
        else if ( a[i] > 0 ) allneg = false;
    }
    
    int imax,imin;
    REP(i,N){
        if ( amax == a[i] ) imax = i;
        if ( amin == a[i] ) imin = i;
    }
    
    vector<pint> ans;
    if ( allpos ){
        for ( int i = 1; i < N; ++i){
            ans.push_back(pint(i-1,i));
        }
    } else if ( allneg ){
        for ( int i = N-1; i >= 1; --i){
            ans.push_back(pint(i,i-1));
        }
    } else {
        if ( abs(amax) >= abs(amin) ){
            REP(i,N){
                //if ( i == imax ) continue;
                ans.push_back(pint(imax,i));
            }
            for ( int i = 1; i < N; ++i){
                ans.push_back(pint(i-1,i));
            }
        } else {
            REP(i,N){
                //if ( i == imin ) continue;
                ans.push_back(pint(imin,i));
            }
            for ( int i = N-1; i >= 1; --i){
               ans.push_back(pint(i,i-1));
           }
        }
    }
    
    
    cout << ans.size() << endl;
    for ( int i = 0; i < ans.size(); ++i){
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
    
    
    
    
    return 0;
}
