#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;


int main(int argc, char const *argv[]) {
  string s;
  std::cin >> s;
  vvi ans = vv(0, 2, 0, int);
  bool flag = true;
  if(s[s.size()-1]=='1'||s[0]!='1') flag = false;
  for(int i=0;i<s.size()-1;i++) if(s[i]!=s[s.size()-2-i]) flag = false;
  if(!flag){
    std::cout << -1 << '\n';
    return 0;
  }
  int now = 1, par = 1;
  for(int i=0;i<s.size()-1;i++, now++){
    if(s[i]=='1') ans.push_back(vector<int> {now+1, par}), par = now+1;
    else ans.push_back(vector<int> {par, now+1});
  }
  for(int i=0;i<s.size()-1;i++) std::cout << ans[i][0] << " " << ans[i][1] << '\n';
  return 0;
}
