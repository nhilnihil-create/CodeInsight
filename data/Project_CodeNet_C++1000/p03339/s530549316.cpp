#include <bits/stdc++.h>
#define MODNum 1000000007
#define REP(type, i, a, b) for( type i = a; i < b; i++ )
typedef long long ll;

using namespace std;

int main (void) {
    int N, ans;
    string S;
    cin >> N;
    cin >> S;
    vector<int> West(N);
    vector<int> East(N);
    if ( S.at(0) == 'W' ) West.at(0) = 1;
    else West.at(0) = 0;
    if ( S.at(N-1) == 'E' ) East.at(N-1) = 1;
    else East.at(N-1) = 0;
    REP(int,i,1,N){
        if ( S.at(i) == 'W' ) West.at(i) = 1 + West.at(i-1);
        else West.at(i) = West.at(i-1);
        if ( S.at(N-1-i) == 'E' ) East.at(N-1-i) = 1 + East.at(N-1-i+1);
        else East.at(N-1-i) = East.at(N-1-i+1);
    }
    ans = N;
    /*REP(int,i,0,N) cout << West.at(i) << " ";
    cout << endl;
    REP(int,i,0,N) cout << East.at(i) << " ";
    cout << endl;*/
    REP(int,i,0,N){
        ans = min(ans,West.at(i) + East.at(i) - 1);
    }
    cout << ans << endl;
    return 0;
}
