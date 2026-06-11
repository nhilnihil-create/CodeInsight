#include <iostream> // cout, endl, cin
#include <cmath> //sqrt pow
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
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int n;
  cin >> n;
  vi cnt(55556,1);
  cnt[0] = cnt[1] = 0; //cnt[0] は１が素数かどうか
  rep(i, 55556){
    if(cnt[i]){
      if(i % 5 != 1) cnt[i] = 0;
      for(int j = i + i; j < 55555; j += i) cnt[j] = 0;
    }
  }
  int count = 0;
  rep(i, 55555){
    if(cnt[i]){
      count++;
      if(count != n) cout << i << " ";
      else{
        cout << i << endl;
        return 0;
      }
    }
  }
}