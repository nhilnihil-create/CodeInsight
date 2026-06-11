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
    int N;
    cin>>N;
    vector<int>A(N);
    rep(i,N){
        cin>>A[i];
    }
    sort(A.rbegin(),A.rend());
    int a=0;
    int b=0;
    rep(i,N){
        if(i+1<N){
        a+=A[i];
        b+=A[i+1];
        i++;
        }
        else{
          a+=A[i];
        }
    }
  cout<<a-b<<endl;
}
