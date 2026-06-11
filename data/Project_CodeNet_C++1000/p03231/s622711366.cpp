#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    long g = __gcd(n,m);
    long a = n/g,b=m/g,flag = 0;
    for(long i=0;i<g;i++){
      if(s[a*i]!=t[b*i]){
        flag = 1;
        break;
      }
    }  
    if(flag) cout << -1 << endl;
    else cout << g*a*b << endl;
}
