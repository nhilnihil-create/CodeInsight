#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;

int n,k,a[10];
string s;

int main() {
  rep(i,4){
  cin >> n; a[n]++;
  }
  if(a[1]==1&&a[9]==1&&a[7]==1&&a[4]==1)
  cout << "YES" << endl;
  else 
  cout << "NO" << endl;
}