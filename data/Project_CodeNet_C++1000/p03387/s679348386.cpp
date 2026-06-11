#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c,cnt=0; cin>>a>>b>>c;
  while(a!=b||b!=c){
    if(a==b&&b>c) c+=2;
    else if(b==c&&c>a) a+=2;
    else if(c==a&&a>b) b+=2;
    else if(a>b&&a>c) b++,c++;
    else if(b>c&&b>a) c++,a++;
    else if(c>a&&c>b) a++,b++;
    cnt++;
  }
  cout<<cnt;
}