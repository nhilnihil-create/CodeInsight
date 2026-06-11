#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans*= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
    int A,B,C;
    cin>>A>>B>>C;
    int D=max(A,B);
    int E=max(D,C);
    A=E-A;
    B=E-B;
    C=E-C;
    int ans=0;
    int S=max(A,B);
    int X=max(S,C);
    ans+=(A+B+C-X);
    if(C<A&&B<A){
        A=A-(A+B+C-X);
        ans+=(A+1)/2;
        if(A%2==1){
            ans++;
        }
    }
    else if(B<C&&A<C){
        C=C-(A+B+C-X);
        ans+=(C+1)/2;
        if(C%2==1){
            ans++;
        }
    }
    else{
        B=B-(A+B+C-X);
        ans+=(B+1)/2;
        if(B%2==1){
            ans++;
        }
    }
    cout<<ans<<endl;
}


