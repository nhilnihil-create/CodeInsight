#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    string S;
    cin >> S;
    int N = S.length();

    if(S[N-1] == '1' || S[0] == '0'){
        cout << -1 << endl;
        return 0;
    }

    REP(i,N-1){
        int rem = N-2 - i;
        if(S[i] != S[rem]){
            cout << -1 << endl;
            return 0;
        }
    }

    S[N-1] = '1';
    int par = N-1;
    for(int i = N-2; i >= 0; i--){
        printf("%d %d\n", i+1, par+1);
        if(S[i] == '1'){
            par = i;
        }
    }

    return 0;
}
