#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;


int main(){
  int N;
  cin >> N;
  vector<int> S;
  rep(i, N){
    int s;
    cin >> s;
    S.push_back(s);
  }
  
  int ans = 0;
  for(int c: S){
    ans += (c-1);
  }

 cout << ans << endl;
}
   
      

    

   
      