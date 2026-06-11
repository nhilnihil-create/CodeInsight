#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  vector<int> s(10);
  s[a]++;
  s[b]++;
  s[c]++;
  s[d]++;
  if(s[1]&&s[9]&&s[7]&&s[4]){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}