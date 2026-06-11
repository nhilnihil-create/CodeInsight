#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;

 int main(){

 string s;
  cin>>s;

  if(s[0] == s[1] && s[1] == s[2] && s[2] == s[0])
    cout<<s<<endl;
  else{

    int n = s[0]-'0';
    int integer = (s[2]-'0') + (s[1]-'0')*10+ (s[0]-'0')*100;


    int before = n*100+n*10+n;

     n += 1;
    int after = (n)*100+(n)*10+(n);

    if(integer > before)
        cout<<after<<endl;
    else
        cout<<before<<endl;

  }

 return 0;
 }