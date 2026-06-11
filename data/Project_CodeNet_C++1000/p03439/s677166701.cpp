#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll mkval(string s){
  if(s=="Vacant"){
    return 0;
  }else if(s=="Male"){
    return 1;
  }else{
    return 2;
  }
}
signed main(){
  ll n,now,left,right,m,fi;
  string s;
  cin >> n;
  cout << 0<<endl;
  cin >> s;
  now= mkval(s);
  if(now==0){
    return 0;
  }
  fi=now;
  left = 1;
  right = n;
  while(true){
    m = (left+right)/2;
    cout << m << endl;
    cin >> s;
    now = mkval(s);
    if(now==0){
      return 0;
    }
    if((m%2==1&&fi!=now)||(m%2==0&&fi==now)){
      left = m+1;
    }else{
      right = m;
    }
  }
}
