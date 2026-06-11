#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  int h[N];
  for(int i=0;i<N;i++){
    cin >> h[i];
  }
  int ans = 0;
  for(int i=0;i<N-1;i++){
    if(h[i]>=h[i+1]){
      ans += h[i];
      ans -= h[i+1];
    }
  }
  ans += h[N-1];
  cout << ans << endl;
}
