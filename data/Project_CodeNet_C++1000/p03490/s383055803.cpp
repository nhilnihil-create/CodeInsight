#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;

string s;
lli x,y;

vll mvx;
vll mvy;

vector<string> split(string::iterator begin,string::iterator end,char sep){
  vector<string> ret;
  for(auto itr = begin;;itr++){
    auto jtr = itr;
    while(jtr != end && *jtr != sep) jtr++;
    // cout << string(itr,jtr) << endl;
    ret.push_back(string(itr,jtr));
    itr = jtr;
    if(itr == end) break;
  }
  return ret;
}

bool solve(vll &x,lli t){
  lli s = accumulate(x.begin(),x.end(),0)+10;
  mat dp = mat(x.size()+1,vll(s*2+1,0));
  dp[0][s] = 1;
  for(lli i = 0;i < x.size();i++){
    for(lli j = 0;j < s*2;j++){
      if(dp[i][j] == 1) dp[i+1][j-x[i]] = dp[i+1][j+x[i]] = 1;
    }
  }
  if(s+t < dp[x.size()].size() && dp[x.size()][s+t] == 1) return true;
  else return false;
}

int main(){
  cin >> s;
  cin >> x >> y;
  vector<string> order = split(s.begin(),s.end(),'T');
  x -= order[0].size();
  for(lli i = 1;i < order.size();i++){
    if(i%2 == 0) mvx.push_back(order[i].size());
    else mvy.push_back(order[i].size());
  }
  // for(lli i = 0;i < mvx.size();i++) cout << mvx[i] << endl;
  // for(lli i = 0;i < mvy.size();i++) cout << mvy[i] << endl;
  if(solve(mvx,x) && solve(mvy,y)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
