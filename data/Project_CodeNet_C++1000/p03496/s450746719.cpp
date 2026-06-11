#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  vector<pair<int,int> > ans;

  int maxx = *max_element(all(a)), minn = *min_element(all(a));
  int maxx_pos = 0,minn_pos = 0;

  for(int i = 0; i < n; i++){
    if(a[i] == maxx) maxx_pos = i;
    if(a[i] == minn) minn_pos = i;
  }


  if(abs(maxx) > abs(minn)){
    for(int i = 0; i < n; i++){
      ans.push_back(pair<int,int>(maxx_pos+1,i+1));
    }
    for(int i = 0; i < n-1; i++){
      ans.push_back(pair<int,int>(i+1,i+2));
    }
  }else{
    for(int i = 0; i < n; i++){
      ans.push_back(pair<int,int>(minn_pos+1,i+1));
    }
    for(int i = n-1; i >= 1; i--){
      ans.push_back(pair<int,int>(i+1,i));
    }
  }

  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++){
    cout << ans[i].first << " " << ans[i].second << endl;
  }

  return 0;
}