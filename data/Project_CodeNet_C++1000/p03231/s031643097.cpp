/**
*    author:  souzai32
*    created: 02.08.2020 15:09:11
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

long int gcd(long  a, long int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

long int lcm(long int a, long int b)
{
   return a * b / gcd(a, b);
}

int main() {

    long int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    bool ans=true;

    rep(i,gcd(n,m)){
        if(s.at(n*i/gcd(n,m))!=t.at(m*i/gcd(n,m))){
            ans=false;
            break;
        }
    }

    if(ans) cout << lcm(n,m) << endl;
    else cout << -1 << endl;

    return 0;
}