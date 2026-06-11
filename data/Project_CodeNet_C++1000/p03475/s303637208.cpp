#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i, N) for (int i = 0; i < (int)(N); i++)

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int N;
vector<int> C,S,F;

int next_time( int s, int i ){
    int quo = ( s + (F[i]-1) ) / F[i];
    int dep;
    if ( quo < ( S[i] / F[i] ) ) dep = S[i];
    else dep = F[i] * quo;
    return dep + C[i];
}

int main() {
    cin >> N;
    C.resize(N-1); S.resize(N-1); F.resize(N-1);
    REP(i,N-1) cin >> C[i] >> S[i] >> F[i];
    
    REP(i,N-1){
        //cout << "station" << i << endl;
        int s = S[i];
        for ( int j = i; j < N-1; ++j){
            s = next_time(s,j);
            //cout << "time" << s << endl;
        }
        cout << s << endl;
    }
    cout << 0 << endl;
    
    
    
    return 0;
}
