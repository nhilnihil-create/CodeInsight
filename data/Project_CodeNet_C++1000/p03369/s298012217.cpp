#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i< (n) ; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main(){
  int n=0;
  string s;
  cin >> s;
  if(s[0]=='o') n++;
  if(s[1]=='o') n++;
  if(s[2]=='o') n++;
  cout << 700+n*100 <<endl;
    return 0;
}
