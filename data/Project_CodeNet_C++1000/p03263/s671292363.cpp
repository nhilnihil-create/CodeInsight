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
  int H,W;
  cin >> H >> W;
  vector< vector<int> > A(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> A[i][j];
    }
  }
  ll ans=0;
  queue< pair<int,int> > sol;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(A[i][j]%2==0){
        continue;
      }
      if(i==H-1 &&  j==W-1){
        continue;
      }
      ans++;
      sol.push(make_pair(i+1,j+1));
      if(j!=W-1){
        A[i][j+1]++;
      }
      else{
        A[i+1][j]++;
      }
    }
  }
  cout << ans << endl;
  while(!sol.empty()){
    int y=sol.front().first;
    int x=sol.front().second;
    sol.pop();
    cout << y << " " << x << " ";
    if(x!=W){
      cout << y << " " << x+1 << endl;
    }
    else{
      cout << y+1 << " " << x << endl;
    }
  }
  return 0;
}