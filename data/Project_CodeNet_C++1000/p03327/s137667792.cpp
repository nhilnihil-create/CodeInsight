#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());

typedef long long ll;

int main(){
  int n;
  cin >> n;
  n /= 1000;
  char ans = n + 'C';
  cout << "AB" << ans << endl;
}