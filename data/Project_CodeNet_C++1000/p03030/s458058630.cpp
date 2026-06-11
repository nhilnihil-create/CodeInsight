#include <algorithm>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define repn(i,n)  rep(i,0,n)

const double EPS = 1e-5;
const int MOD = 1e9+7;

const int N = 100;

vector<string> name(N);
map<string, vector<int>> point;
map<pair<string, int>, int> number;



int main(){
  int n;
  cin >> n;

  string a;
  int b;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    name[i] = a;
    point[a].emplace_back(b);
    number[make_pair(name[i],b)] = i+1;
  }

  sort(name.begin(), name.end(), [](const std::string& a, const std::string& b) {
       for (int i = 0 ; i < std::min(a.size(), b.size()) ; i++) {
         if (a[i] != b[i]) {
           return a[i] < b[i];
         }
       }
       return a.size() < b.size();
     });

  for(auto &elem: point){
    sort(elem.second.begin(), elem.second.end(), greater<int>());
    //cout << elem.first << endl;
  }

  for(auto &town: point){
    for(auto &elem: town.second){
      //cout << town.first << endl;
      //cout << elem << endl;
      cout << number[make_pair(town.first, elem)] << endl;
    }
  }




  return 0;
}
