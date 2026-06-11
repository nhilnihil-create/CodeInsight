#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
int main(){
  string str;
  int n;
  cin >> n;
  str = to_string(n);
  int ans=0;
  rep(i,4){
    if(str[i]=='2'){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}