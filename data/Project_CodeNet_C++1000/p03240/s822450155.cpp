#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> X(N),Y(N),H(N);
  for(int i=0;i<N;i++){
    cin >> X[i] >> Y[i] >> H[i];
  }
  bool flag=true;
  for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
      int height=0;
      for(int k=0;k<N;k++){
        if(H[k]!=0){
          height=H[k]+abs(i-X[k])+abs(j-Y[k]);
          break;
        }
      }
      flag=true;
      for(int k=0;k<N;k++){
        if(max(height-abs(X[k]-i)-abs(Y[k]-j),0)!=H[k]){
          flag=false;
          break;
        }
      }
      if(flag){
        cout << i << " " << j << " " << height << endl;
        return 0;
      }
    }
  }
}