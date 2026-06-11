#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

void change(int n, vector<int> &V){
 int i = 0;
  if(n == 0){
    V.push_back(0);
  }
  while(n != 0){
    int x;
    x = n%(-2);
    if(x==-1) x = 1;
    V.push_back(x);
    n = (n-x)/(-2);
   
   i++;
  }
}

int main(){
  int N;
  cin >> N;
  vector<int> ans(0);
  change(N, ans);
  for(int i = ans.size()-1; i >= 0; i--){
    cout << ans[i];
  }
  cout << endl;
}