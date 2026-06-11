#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <cstring>
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
#include <numeric>
#include <float.h>
using namespace std;
// repマクロの定義
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// allマクロの定義
#define all(v) v.begin(), v.end()
typedef unsigned long long ll;

 //最大公約数求める関数
auto my_gcd(auto n , auto m){
  if(n < m){
    auto tmp = n;
    n = m;
    m = tmp;
  }
  auto l  = n % m;
  while(l != 0){
    n = m;
    m = l;
    l = n % m;
}
return m;
}

//char⇒int関数
 int ctoi(char c) {
 	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}



int main(){
int H,W;cin >> H >> W;
vector<string> S(H);
rep(i,H) cin >> S[i];

vector<int> dx = {0,0,-1,1};
vector<int> dy = {1,-1,0,0};
int cnt = 0;
bool flag = true;
rep(i,H){
	rep(j,W){
		if(S[i][j] == '#'){
			rep(k,4){
				if(i+dy[k] < H && 0 <= i+dy[k] && j+dx[k] < W && 0 <= j + dx[k] ){
				if(S[i+dy[k]][j+dx[k]] == '#'){
					cnt++;
				}
				
			}

			}
			if(cnt == 0){
				flag = false;
			}
			cnt = 0;
		}
	}
}
if(flag) cout << "Yes" << endl;
else cout << "No" << endl;
}