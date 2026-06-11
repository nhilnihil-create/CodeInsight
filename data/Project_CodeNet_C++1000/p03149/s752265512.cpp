#include <bits/stdc++.h>

using namespace std;

int main(){
 int a,b,c,d; 
  cin >> a >> b >> c >> d;
 
  int cnt[10]={0};
  
  cnt[a]++;
  cnt[b]++;
  cnt[c]++;
  cnt[d]++;
  
  if(cnt[1]==1&&cnt[9]==1&&cnt[7]==1&&cnt[4]==1) cout << "YES" << endl;
  else cout << "NO" << endl;
  

}
