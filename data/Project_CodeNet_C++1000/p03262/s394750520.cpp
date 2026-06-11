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

int GCD(int a,int b){
  if(b==0){
    return a;
  }
  else{
    return GCD(b,a%b);
  }
}

int main(){
  int N,X;
  cin >> N >> X;
  int ans=0;
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
    x=abs(x-X);
    ans=GCD(ans,x);
  }
  cout << ans << endl;
}