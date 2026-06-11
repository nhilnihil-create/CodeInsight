# include <bits/stdc++.h>
using namespace std;

long long ceil(long long a, long long b){
  return a/b + ((a%b) != 0);
}

int main(){

  long long a[100005], l[100005], r[100005];
  int K;
  cin >> K;
  for(int i=1; i<=K; i++) cin >> a[i];
  l[K] = r[K] = 2;

  for(int i=K-1; i>=0; i--){
    l[i] = 1ll * ceil(l[i+1], a[i+1]) * a[i+1];
    r[i] = 1ll * r[i+1]/a[i+1] * a[i+1] + a[i+1] - 1;
  }

  if(l[0] > r[0]) {
    cout << -1 << endl;
    return 0;
  }
  cout << l[0] << " " << r[0] << endl;
  return 0;
}
