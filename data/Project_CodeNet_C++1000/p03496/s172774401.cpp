#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int N;
  cin >> N;
  int a[N];
  for(int i = 0; i < N; i++) cin >> a[i];

  int mx = *max_element(a, a + N);
  int mx_ind = max_element(a, a + N) - a;
  int mn = *min_element(a, a + N);
  int mn_ind = min_element(a, a + N) - a;

  cout << 2 * N - 1 << endl;

  if(abs(mx) >= abs(mn)){
    for(int i = 0; i < N; i++){
      a[i] += mx;
      cout << mx_ind + 1 << " " << i + 1 << endl;
    }
  } else {
    for(int i = 0; i < N; i++){
      a[i] += mn;
      cout << mn_ind + 1 << " " << i + 1 << endl;
    }
  }

  if(a[0] > 0){
    for(int i = 0; i < N - 1; i++){
      cout << i + 1 << " " << i + 2 << endl;
    }
  } else {
    for(int i = N; i > 1; i--){
      cout << i << " " << i - 1 << endl;
    }
  }

  return 0;
}