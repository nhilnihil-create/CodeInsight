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
  char before;
  map<string, int> s;
  rep(i, n){
    string w;
    cin >> w;
    if(i){
      if(w[0] != before){
        cout << "No" << endl;
        return 0;
      }else before = w[w.size() - 1];
      if(s[w] >= 1){
        cout << "No" << endl;
        return 0;
      }
      s[w]++;
    }else{
      before = w[w.size() - 1];
      s[w]++;
    }
  }
  cout << "Yes" << endl;
}