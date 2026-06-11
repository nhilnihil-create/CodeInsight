#include <bits/stdc++.h>
#define MODNum 1000000007
#define REP(type, i, a, b) for( type i = a; i < b; i++ )
typedef long long ll;

using namespace std;

int main (void) {
    ll N, ans;
    cin >> N;
    vector<ll> A(N),B(N);
    REP(int,i,0,N){
        cin >> A.at(i);
        B.at(i) = A.at(i);
    }
    sort(A.begin(),A.end());
    ll Med1 = A.at(N/2-1);
    ll Med2 = A.at(N/2);
    REP(int,i,0,N){
        if ( B.at(i) <= Med1 ) cout << Med2 << endl;
        else cout << Med1 << endl;
    }
    return 0;
}