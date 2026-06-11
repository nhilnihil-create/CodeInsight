#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    int N, D, X;
    cin >> N >> D >> X;
    vi A(N);
    rep(i, N) cin >> A[i];

    int choco = 0;
    rep(i, N){
        rep(j, D){
            if(j*A[i] + 1 <= D){
                choco++;
            }
        }
        cout << endl;
    }

    cout << choco + X << endl;
    return 0;
}