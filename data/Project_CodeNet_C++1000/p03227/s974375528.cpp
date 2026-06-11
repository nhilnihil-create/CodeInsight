#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int n = s.length();
  if(n==2){
    cout << s << endl;
  }else{
    reverse(s.begin(),s.end());
    cout << s << endl;
  }
  return 0;
}