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
using namespace std;
using ll = long long;

int main(){
  int N;
  cin >> N;
  vector<int> A(N),B(N),C(N);
  int Amax=0,Amin=1e9+5,Cmax=0,Cmin=1e9+5;
  for(int i=0;i<N;i++){
    cin >> A[i];
    Amax=max(Amax,A[i]);
    Amin=min(Amin,A[i]);
  }
  for(int i=0;i<N;i++){
    cin >> B[i];
  }
  for(int i=0;i<N;i++){
    cin >> C[i];
    Cmax=max(Cmax,C[i]);
    Cmin=min(Cmin,C[i]);
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());
  ll ans=0;
  for(int b:B){
    if(b<Amin || b>=Cmax){
      continue;
    }
    auto Ait=lower_bound(A.begin(),A.end(),b);
    auto Cit=upper_bound(C.begin(),C.end(),b);
    ans+=(Ait-A.begin())*(C.end()-Cit);
  }
  cout << ans << endl;
}