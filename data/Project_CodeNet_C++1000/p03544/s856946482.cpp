#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {
  int N; cin >> N;
  ll L[100];
  L[0] = 2;
  L[1] = 1;
  for(int i = 2; i <= N; i++){
    L[i] = L[i-1] + L[i-2];
  } 
  cout << L[N] << endl;
	return 0;
}

