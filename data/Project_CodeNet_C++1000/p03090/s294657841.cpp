#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  int n;
  cin >> n;
  set<pair<int,int>> st;
  for(int i = 1;i <= n;i++){
    for(int j = i+1;j <= n;j++){
      st.insert(make_pair(j,i));
    }
  }
  if(n&1){
    for(int i = 1,j = n-1;i < j;i++,j--){
      st.erase(make_pair(j,i));
    }
  }else{
    for(int i = 1,j = n;i < j;i++,j--){
      st.erase(make_pair(j,i));
    }
  }
  cout << st.size() << "\n";
  for(auto iter = st.begin();iter != st.end();iter++){
    cout << (*iter).first << " " << (*iter).second << "\n";
  }




  return 0;
}