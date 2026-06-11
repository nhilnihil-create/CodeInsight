#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=0, tmp=0;
vector<ll> A(MAXN, 0), G1(MAXN, 0), G2(MAXN, 0);

int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> A[i];
        if(!i) G1[i]=A[i];
        else G1[i]=gcd(A[i],G1[i-1]);
    }
    for(int i=N-1;i>=0;i--) {
        if(i==N-1) G2[i]=A[i];
        else G2[i]=gcd(A[i],G2[i+1]);
    }
    ans = max(G1[N-2],G2[1]);
    for(int i=1;i<N-1;i++) {
        ans = max(ans, gcd(G1[i-1],G2[i+1]));
    }
    cout << ans << endl;
    return 0;
}