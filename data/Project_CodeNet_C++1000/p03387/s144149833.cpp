#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int ans=0;
  while(a!=b||a!=c){
    ans++;
    if(a>b&&a>c){
      b++;
      c++;
    }else if(b>a&&b>c){
      a++;
      c++;
    }else if(c>a&&c>b){
      a++;
      b++;
    }else if(a<b&&b==c){
      a+=2;
    }else if(b<c&&c==a){
      b+=2;
    }else if(c<a&&a==b)
      c+=2;
  }
  cout << ans << endl;
  return 0;
}