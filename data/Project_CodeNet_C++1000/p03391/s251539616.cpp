#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

long long x[200000];
long long y[200000];
int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
      cin >> x[i] >> y[i];
    }

    long long ans = 0;
    long long less_sum = 0;
    long long less_min = INT_MAX;
    for(int i = 0; i < N; i++){
      if(x[i] < y[i]){
        ans += y[i];
      }
      if(x[i] > y[i]){
        less_sum += y[i];
        less_min = min(less_min, y[i]);
      }
    }
    if(ans != 0) {
      for(int i = 0; i < N; i++){
        if(x[i] == y[i]){
          ans += x[i];
        }
      }
      ans += (less_sum - less_min);
    }
    cout << ans << endl;
    return 0;
}
