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
#include <deque> // dequef
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower

#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define all(a) (a).begin(), (a).end()
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int n;
  cin >> n;
  map<int, int> cnt;
  for(int i = 2; i <= n; i++){
    int num = i;
    for(int j = 2; j <= sqrt(i); j++){
      while(num % j == 0){
        num /= j;
        cnt[j]++;
      }
    }
    if(num >= 2) cnt[num]++;
  }
  vi check(5);
  for(auto x : cnt){
    if(x.second >= 2) check[0]++;
    if(x.second >= 4) check[1]++;
    if(x.second >= 14) check[2]++;
    if(x.second >= 24) check[3]++;
    if(x.second >= 74) check[4]++;
  }
  int num = check[2] * (check[1] - 1);
  num += check[3] * (check[0] - 1);
  num += check[1] * (check[1] - 1) * (check[0] - 2) / 2;
  num += check[4];
  cout << num << endl;
}