#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin  >> n;
  bool IsPrime[55556];
  for(int i=0; i<=55555; i++){
    IsPrime[i] = true;
  }
  IsPrime[0] = false;
  IsPrime[1] = false;
  for(int i=2; i<=55555; i++){
    if(IsPrime[i]){
      for(int j=2; j*i<=55555; j++){
        IsPrime[i*j] = false;
      }
    }
  }
  int cnt = 0;
  vector<int> ans;
  for(int i=1; i<=5555; i++){
    if(IsPrime[10*i+1]){
      cnt++;
      ans.push_back(10*i+1);
      if(cnt==n) break;
    }
  }
  cout << ans[0];
  for(int i=1; i<n; i++){
    cout << " " << ans[i];
  }
  cout << endl;
  return 0;
}
