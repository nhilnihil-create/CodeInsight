#include<bits/stdc++.h>
using namespace std;
int main(){
  string n;
  cin >> n;
  int a=n[0]-'0',b=n[1]-'0',c=n[2]-'0',d=n[3]-'0';
  if(a-b-c-d==7)cout << a << '-' << b << '-' << c << '-' << d << '=' << 7 << endl;
  else if(a-b-c+d==7)cout << a << '-' << b  << '-' << c << '+' << d << '='<< 7 << endl;
  else if(a-b+c+d==7)cout << a << '-' << b << '+' << c << '+' << d << '=' << 7 << endl;
  else if(a+b+c+d==7)cout << a << '+' << b << '+' << c << '+' << d  << '=' << 7 << endl;
  else if(a-b+c-d==7)cout << a << '-' << b  << '+'  << c << '-' << d << '=' << 7 << endl;
  else if(a+b-c-d==7)cout << a << '+' << b << '-' << c << '-' << d << '=' << 7 << endl;
  else if(a+b+c-d==7)cout << a << '+' << b << '+' << c << '-' << d << '=' << 7 << endl;
  else if(a+b-c+d==7)cout << a << '+' << b << '-' << c << '+' << d << '=' << 7 << endl;
}