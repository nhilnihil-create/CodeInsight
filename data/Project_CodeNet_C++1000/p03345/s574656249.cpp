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
    ll A,B,C,K;
    cin>>A>>B>>C>>K;
    if(K%2==1){
        cout<<B-A<<endl;
    }
    else{
        cout<<A-B<<endl;
    }
}
