#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   string s;
   cin >>s;
   bool heisei=true;
   if(s[5]-'0'>0)heisei=false;
   else if(s[6]-'0'>4)heisei=false;
   if(heisei)puts("Heisei");
   else puts("TBD");
   return 0;
}