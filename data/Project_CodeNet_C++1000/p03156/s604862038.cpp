#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int p[n];
  int first=0,second=0,third=0;
  rep(i,n) {
    cin >> p[i];
    if(p[i]<=a){
      first++;
    }else if(p[i]>a && p[i]<=b){
      second++;
    }else{
      third++;
    }
  }
  int ans = min(first,min(second,third));
  cout << ans << endl;
  return 0;
}