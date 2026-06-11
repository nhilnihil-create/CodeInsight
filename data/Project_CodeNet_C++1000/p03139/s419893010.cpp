#include <bits/stdc++.h>
using namespace std;
const long long mod = pow(10, 9) + 7;
const long long INF = 1LL << 60;
template <class T> bool chmin(T& a, T b){if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b){if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
long long divCeil(long long A, long long B) {return (A + (B - 1)) / B;}

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  
  int max = min(A, B);
  int min = (A + B) - N;
  if (min < 0) min = 0;
  
  cout << max << " " << min << endl;
}