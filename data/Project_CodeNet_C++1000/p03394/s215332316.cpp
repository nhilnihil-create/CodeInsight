#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

const int P=30000;

int main(){
  int N;
  cin>>N;

  if(N==3){
    cout<<"2 5 63"<<endl;
    return 0;
  }else if(N==4){
    cout<<"2 5 20 63"<<endl;
    return 0;
  }

  vector<int> ans;
  ans.push_back(2);
  ans.push_back(8);
  ans.push_back(14);
  ans.push_back(3);
  ans.push_back(9);

  vector<int> t;
  for(int i=2;i<=P;i+=2){
    if(i%3==1) t.push_back(i);
    if(t.size()==3){
      for(auto x:t) ans.push_back(x);
      t.clear();
    }

    if(ans.size()+3>N) break;
  }
  vector<int> f;
  for(int i=16;i<=P;i+=2){
    if(i%3==2) f.push_back(i);
    if(f.size()==3){
      for(auto x:f) ans.push_back(x);
      f.clear();
    }

    if(ans.size()+3>N) break;
  }

  for(int i=0;i<min(min(N-ans.size(),t.size()),f.size());i++){
    ans.push_back(t[i]);
    ans.push_back(f[i]);
  }

  t.clear();
  for(int i=12;i<=P;i+=3){
    if(i%2!=0) t.push_back(i);
    if(t.size()==2){
      for(auto x:t) ans.push_back(x);
      t.clear();
    }

    if(ans.size()+2>N) break;
  }

  for(int i=1;i<=P;i++){
    if(ans.size()==N) break;
    if(i%6==0){
      ans.push_back(i);
    }
  }
  for(auto v:ans) cout<<v<<" ";
  cout<<endl;

  return 0;
}
