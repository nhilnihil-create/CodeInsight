#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  long double T, A;
  cin >> T >> A;

  long double ans;
  long double abs_diff = 1000.0;

  for(int i = 0; i < N; i++){
    long double h;
    cin >> h;
    long double tmp_abs_diff = abs(T - 0.006 * h - A);

    if(tmp_abs_diff < abs_diff){
      abs_diff = tmp_abs_diff;
      ans = i;
    }
  }
  cout << ans+1 << endl;
}
