#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  ll n;
  cin >> n;
  if(n==0){
    cout << 0 << endl;
    return 0;
  }
  ll base = 1;
  int cnt = 0;
  vector<int> ans;
  while(n!=0){
    if(n%abs(base*2)){
      ans.push_back(1);
      n-=base;
    }else{
      ans.push_back(0);
    }
    base *= -2;
  }
  for(int i=0; i<ans.size(); i++){
    cout << ans[ans.size()-i-1];
  }
  cout << endl;
  return 0;
}
