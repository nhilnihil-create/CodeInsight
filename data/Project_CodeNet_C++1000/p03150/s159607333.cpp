#include<iostream>
#include<string>
using namespace std;
int main(){
  string s,a,b,k = "keyence";cin >> s;int i,c,d,n = s.size();bool ans = false;
  for(i=1;i<7;i++){
    a = k.substr(0,i);b = k.substr(i);
    c = s.find(a);d = s.rfind(b);
    if(c != string::npos && d != string::npos && ((c==0 && (d==n-(7-i) || d==c)) || c==n-7)) ans = true;
  }
  cout << ((ans) ? "YES":"NO") << endl;
}
  
