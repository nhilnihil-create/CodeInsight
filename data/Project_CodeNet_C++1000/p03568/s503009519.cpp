#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int N = 0,count = 1;
  cin >> N;
  vector<int>A(N);
  rep(i,N){
    cin >> A[i];
    if(A[i] % 2 == 0){
      count *= 2;
    }
  }
  cout << pow(3,N) - count;
}