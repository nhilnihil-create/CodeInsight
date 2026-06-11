#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
/*ていればok
*/


int main() {
 ll N,M;
 cin >> N >> M;
 string S,T;
 cin >> S >> T;

 ll g = gcd(N,M);
 bool flag = true;
 for(int i = 0;i<=g-1;i++){
     if(S[i*N/g] != T[i*M/g]){
         flag = false;
         break;
     }
 }
 if(flag) cout << N*M/g << endl;
 else cout << -1 << endl;
}
