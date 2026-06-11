#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intput(i) cout << i << endl
#define ll long long
#define stringput(s) cout << (string)(s) << endl

int main(){
  int N;
  cin >> N;
  if(N < 1200) cout << "ABC" << endl;
  else if(1199 < N && N < 2800) cout << "ARC"  << endl;
  else cout << "AGC" << endl;
}