#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
// vector<vector<int>> A(3, vector<int>(4));
int main() {
    int N;
    cin>>N;
   vector<tuple<string,int,int>> A(N);
    rep(i,N){
        cin >> get<0>(A[i]) >> get<1>(A[i]) ;
        get<2>(A[i]) = i + 1;
        get<1>(A[i]) *= -1;
    }
    sort(A.begin(),A.end());
    rep(i,N){
        cout<<get<2>(A[i])<<endl;
    }
}

