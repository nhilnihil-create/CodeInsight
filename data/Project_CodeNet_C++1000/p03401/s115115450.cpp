#include <bits/stdc++.h>
#define MODNum 1000000007
#define REP(type, i, a, b) for( type i = a; i < b; i++ )
typedef long long ll;

using namespace std;

int main (void) {
    int N, ans;
    cin >> N;
    vector<int> A(N+2);
    REP(int,i,1,N+1) cin >> A.at(i);
    A.at(0) = 0;
    A.at(N+1) = 0;
    vector<int> Fee1(N+1);
    vector<int> Fee2(N);
    int Sum = 0;
    REP(int,i,0,N+1){
        Fee1.at(i) = abs(A.at(i+1) - A.at(i));
        Sum += Fee1.at(i);
        //cout << Fee1.at(i) << " ";
    }
    //cout << endl;
    REP(int,i,0,N){
        Fee2.at(i) = abs(A.at(i+2) - A.at(i));
        //cout << Fee2.at(i) << " ";
    }
    //cout << endl;
    REP(int,i,0,N){
        ans = Sum - Fee1.at(i) - Fee1.at(i+1) + Fee2.at(i);
        cout << ans << endl;
    }
    return 0;
}
