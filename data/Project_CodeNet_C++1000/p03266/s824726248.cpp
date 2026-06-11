#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());

typedef long long ll;

ll spow(int a,int n){
  if(n == 0) return 1;
  if(n == 1) return a;
  if(n%2 == 0) return spow(a,n/2)*spow(a,n/2);
  else return a*spow(a,n/2)*spow(a,n/2);
}

int main(){
  ll n,k;
  cin >> n >> k;
  if(k%2) cout << spow(n/k,3) << endl;
  else cout << spow(n/k,3) + spow(2*n/k - n/k,3) << endl;
}
