#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  vector<int> b(N);
  for (int i = 0; i < N; i++){
    cin >> b[i];
  }
  long long sum1 = 0;
  long long sum2 = 0;
  long long sum3 = 0;
  for (int i = 0; i < N; i++){
    sum1 += b[i] - a[i];
    if (a[i] >= b[i]){
      sum2 += a[i] - b[i];
    } else {
      sum3 += (b[i] - a[i] + 1) / 2;
    }
  }
  if (sum1 >= max(sum2, sum3)){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}