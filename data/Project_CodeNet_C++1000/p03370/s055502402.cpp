#include <bits/stdc++.h>
using namespace std;

int main(){

    int N,X;
    cin >> N >> X;
    int i = 0;
    int a[N];
    int sum = 0;
    int cnt = 0;
  
    for(i=0; i<N; i++){
      cin >> a[i];
      sum += a[i];
      cnt++;
    }
    sort(a, a+N);
  
    cout << cnt+(X-sum)/a[0] << endl;
}