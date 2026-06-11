#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i=0; i<N; i++) cin >> a[i];
  vector<long long> b(N);
  for (int i=0; i<N; i++) cin >> b[i];

  long long di = 1;
  long long ans = 0;
  for (int i=0; i<29; i++){
    vector<long long> moda(N);
    vector<long long> modb(N);
    for (int j=0; j<N; j++){
      moda[j] = a[j]%(di*2);
      modb[j] = b[j]%(di*2);
    }
    sort(modb.begin(), modb.end());
    long long tempans = 0;
    for (int j=0; j<N; j++){
      int check = moda[j];
      int T1 = lower_bound(modb.begin(),modb.end(),di-check) - modb.begin();
      int T2 = lower_bound(modb.begin(),modb.end(),di*2-check) - modb.begin();
      int T3 = lower_bound(modb.begin(),modb.end(),di*3-check) - modb.begin();
      int T4 = lower_bound(modb.begin(),modb.end(),di*4-check) - modb.begin();
      tempans += ((T2-T1) + (T4-T3))%2;
    }
    ans += di*(tempans%2);
    di *= 2;
  }
  cout << ans << endl;
}
