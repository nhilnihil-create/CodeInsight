#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N, x;
  cin >> N >> x;

  int a[110];

  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  sort(a, a+N);

  int ans = 0;
  for(int i = 0; i < N; i++){
    x -= a[i];
    if(i == N-1 && x > 0){
      ans--;
    }
    if(x >= 0){
      ans++;
    }else{
      break;
    }
  }

  cout << ans << endl;


}