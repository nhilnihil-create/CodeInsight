#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, sum = 0;
  cin >> N;  
  vector<ll> A(N);
  for(ll i = 0; i < N; i++) {
    cin >> A.at(i);
    if(i == 0) sum += abs(A.at(0));
    else sum += abs(A.at(i) - A.at(i - 1));
  }
  sum += abs(A.at(N - 1));
  for(ll i = 0; i < N; i++) {
    if(i == 0) {
      if(A.at(0) * (A.at(1) - A.at(0)) < 0) cout << sum - 2 * min(abs(A.at(1) - A.at(0)), abs(A.at(0))) << endl;
      else cout << sum << endl;
    }
    else if(i == N - 1) {
      if((A.at(N - 1) - A.at(N - 2)) * (-A.at(N - 1)) < 0) cout << sum - 2 * min(abs(A.at(N - 1) - A.at(N - 2)), abs(A.at(N - 1))) << endl;
      else cout << sum << endl;
    }
    else {
      if((A.at(i) - A.at(i - 1)) * (A.at(i + 1) - A.at(i)) < 0) cout << sum - 2 * min(abs(A.at(i) - A.at(i - 1)), abs(A.at(i + 1) - A.at(i))) << endl;
      else cout << sum << endl;
    }
  }
}