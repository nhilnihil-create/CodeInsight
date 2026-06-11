#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);


int gcd(int a, int b) {
   if (a%b == 0) {
       return(b);
   }
   else {
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b) {
   return a * b / gcd(a, b);
}

int main() {
   int N;
   cin >> N;
   int A[N];
   rep(i,N) {
       cin >> A[i];
   }

   int R[N],L[N];

   L[0] = A[0];
   R[N-1] = A[N-1];

   rep(i,N-1) {
       L[i+1] = gcd(L[i],A[i+1]);
       R[N-1-i-1] = gcd(R[N-1-i],A[N-1-i-1]);
   }
   
   int ans = 1;
   ans = max(L[N-2],R[1]);
   for (int i=1; i<=N-2; i++) {
       ans = max(gcd(L[i-1],R[i+1]),ans);
   }
   cout << ans << endl;
}