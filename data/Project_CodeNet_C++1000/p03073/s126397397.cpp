#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  string s;
  cin >> s;
  int cnt0=0, cnt1=0;
  for(int i=0; i<s.length(); i++){
    if(i%2==0){
      if(s[i]=='0') cnt1++;
      else cnt0++;
    }else{
      if(s[i]=='0') cnt0++;
      else cnt1++;
    }
  }
  int ans = min(cnt0, cnt1);
  cout << ans << endl;
  return 0;
}
