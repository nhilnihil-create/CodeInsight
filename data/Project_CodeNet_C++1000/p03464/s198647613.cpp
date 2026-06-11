# include <bits/stdc++.h>
using namespace std;

int ceil(int a, int b){
  return a/b + ((a%b) != 0);
}

int main(){

  long long a[100005], l, r;
  int K;
  cin >> K;
  for(int i=0; i<K; i++) cin >> a[i];
  l = r = 2;

  for(int i=K-1; i>=0; i--){
    
    if(r < a[i]){
      cout << -1 << endl;
      return 0;
    }

    l = 1ll * ((l-1)/a[i] + 1) * a[i];
    r = 1ll * r/a[i] * a[i] + (a[i] - 1);
    if(l > r) {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << l << " " << r << endl;
  return 0;
}
