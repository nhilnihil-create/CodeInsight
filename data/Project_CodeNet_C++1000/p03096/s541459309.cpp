#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
const long long MOD = 1e9 + 7;

int N;
int A[MAXN];
int PREV[MAXN];
long long DP[MAXN];
int main(void){
    cin >> N;
    for(int i = 1 ; i <= N ; i++) cin >> A[i];

    DP[0] = 1;
    for(int i = 1 ; i <= N ; i++){
        DP[i] = DP[i - 1];
        if(A[i] != A[i - 1]){
            if(PREV[A[i]] != 0){
                DP[i] += DP[PREV[A[i]]];
                DP[i] %= MOD;
            }
        }
        PREV[A[i]] = i;
        //cout << DP[i] << '\n';
    }

    cout << DP[N];
    return 0;
}