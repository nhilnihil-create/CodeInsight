#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  int n;std::cin >> n;
  vector<int> cost(n, 1000000000);
  deque<pair<int, int>> q;
  q.push_back(make_pair(1, 1));
  while(!q.empty()){
    pair<int, int> tmp = q.front();q.pop_front();
    if(cost[tmp.first]<=tmp.second) continue;
    cost[tmp.first] = tmp.second;
    q.push_back(make_pair((tmp.first+1)%n, tmp.second+1));
    q.push_back(make_pair((tmp.first*10)%n, tmp.second));
  }
  std::cout << cost[0] << '\n';
  return 0;
}
