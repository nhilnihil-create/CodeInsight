#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = int(n); i >= 0; --i)
typedef long long LL;
typedef pair<int, int> PII;
  
void f(int a, int b, int k) {
  int small = a<b?a:b;
  int count = 0;
  int ans=0;

  forn(i, small){
  	if(a % i == 0 && b % i == 0){
      //cout << "i " << i << endl;
      count++;
    }
    if(count == k){
      ans = i;
      break;
    }
  }
  cout << ans << endl; 
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b, k;
  cin >> a >> b >> k;
  f(a,b,k);
  return 0;
}