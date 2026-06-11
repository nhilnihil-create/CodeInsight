#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
  int N;
  cin >> N;
  int a[N];
  for (int i=0;i<N;i++){
    cin >> a[i];
  }

  sort(a, a+N);
  int sum1 = 0;
  for (int i=0;i<N;i+=2){
    sum1 += a[i];
  }
  int sum2 = 0;
  for (int i=1;i<N;i+=2){
    sum2 += a[i];
  }

  int ans = max(sum1, sum2) - min(sum1, sum2);
  cout << ans << endl;
  return 0;
}