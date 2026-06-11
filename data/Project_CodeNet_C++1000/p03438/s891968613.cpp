#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    vector<int> A(N),B(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    ll sumA = 0;
    ll sumB = 0;
    ll cntA=0,cntB=0;

    rep(i,N){
        if(A[i]-B[i]>0){
            // Bに1を足す必要がある回数
            cntB += A[i] - B[i];
        }else{
            // Aに2を足す必要がある回数
            cntA += (B[i] - A[i])/2.0;
        }
    }
    if(cntA>=cntB){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}