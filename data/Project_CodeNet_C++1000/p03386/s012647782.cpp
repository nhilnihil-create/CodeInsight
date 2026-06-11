#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
int main() {
    int A,B,K;
    cin>>A>>B>>K;
    if(K*2<=B-A){
        for(int i=0; i<K; i++){
            cout<<A+i<<endl;
        }
        for(int i=B-K+1; i<B+1; i++){
          cout<<i<<endl;
        }
    }
    else{
        for(int i=A; i<B+1; i++){
            cout<<i<<endl;
        }
    }
}