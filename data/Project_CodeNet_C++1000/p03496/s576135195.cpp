#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <tuple>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>

#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long>vll;
typedef pair<int,int> pi;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

int main(){
  int n, maxi = -1000005, mini=1000005, max_idx=0, min_idx=0;
  cin >> n;
  vector<int> data(n);

  for(int i = 0; i < n; i++){
    cin >> data[i];
    if(maxi < data[i]){
      maxi = data[i];
      max_idx = i;
    }
    if(data[i] < mini){
      mini = data[i];
      min_idx = i;
    }
  }

  vector<int> DEBUG = data;
  
  int add, add_idx;
  if(abs(mini) < abs(maxi)){
    add = maxi;
    add_idx = max_idx + 1;
  }else{
    add = mini;
    add_idx = min_idx + 1;
  }

  // cout << "add_idx: " << add_idx << endl;
  
  vector<pair<int,int>> ans;
  for(int i = 0; i< n; i++){
    ans.pb(mp(add_idx, i + 1));
    DEBUG[i] += add; 
  }

  if(add>=0){
    for(int i = 1; i < n; i++){
      DEBUG[i] += DEBUG[i-1];
      ans.pb(mp(i, i + 1));
    }
  }else{
    for(int i = n - 1; i > 0; i--){
      DEBUG[i - 1] += DEBUG[i];
      ans.pb(mp(i + 1, i));
    }
  }

  
  /*for(auto x : DEBUG)cout << x << " ";
  cout << endl;
  */
  cout << ans.size() << endl;
  
  for(auto x : ans){
    cout << x.first << " " << x.second << endl;
  }
  return 0;
}
