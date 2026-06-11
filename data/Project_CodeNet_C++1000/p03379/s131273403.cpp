#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long MOD = 1e9+7;
int MAX_INT = 1e9;

long long gcd(long long a, long long b){
  if(b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long N;
  cin >> N;
  vector<long long> X(N), Y(N);
  for(int i = 0; i < N; i++) {
    cin >> X[i];
    Y[i] = X[i];
  }
  sort(Y.begin(), Y.end());
  for(int i = 0; i < N; i++) {
        if(X[i] < Y[N/2]) {
            cout << Y[N/2] << endl;
        }
        else {
            cout << Y[N/2-1] << endl;
        }
    }

  return 0;
}
