#include <bits/stdc++.h>
using namespace std;

int main() {

  int N , x;
  cin >> N >> x;

  int ans=0;

  int y = x;

  vector<int> a(N);

  for(int i=0;i<N;i++){
    cin >> a[i];
  }

  sort(a.begin() , a.end());

  for(int i=0;i<N ; i++){

    if(x>=a[i]){
      x -= a[i];
      ans++;
    }

    else break;

  }

  if(ans==N){
    int all=0;
    for(int i=0 ; i<N ;i++){
      all += a[i];
    }

    if(all < y) ans--;
    else ;
  }

  cout << ans << endl;
}