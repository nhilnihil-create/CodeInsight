#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

int main(int argc, char const* argv[])
{
  int a, b;
  cin >> a >> b;
  cout << 100 << " " << 100 << endl;
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      if(i < 50){
        // bg: black
        if(a > 1 && (i + j) % 2 == 0 && i % 2 == 0){
          cout << ".";
          a--;
        }
        else cout << "#";
      }else{
        if(b > 1 && (i + j) % 2 == 0 && i % 2 == 1){
          cout << "#";
          b--;
        }
        else cout << ".";
      }
    }
    cout << endl;
  }
	return 0;
}
