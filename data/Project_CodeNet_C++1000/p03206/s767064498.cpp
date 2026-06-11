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
   ll d;cin >>d;
   string c="Christmas";
   string e="Eve";
   if(d==25)cout <<c<<endl;
   if(d==24)cout <<c<<" "<<e<<endl;
   if(d==23)cout <<c<<" "<<e<<" "<<e<<endl;
   if(d==22)cout <<c<<" "<<e<<" "<<e<<" "<<e<<endl;
   return 0;
}