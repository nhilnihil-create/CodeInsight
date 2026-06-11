#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


int main(){
 int n,m;
 cin >> n >>m;
 VI k(m),p(m);
 vector<VI> s(m,VI(n));
 rep(i,m){
     cin >> k.at(i);
     rep(j,k.at(i)){
         cin >> s.at(i).at(j);
     }
 }
 rep(i,m)cin >> p.at(i);
 int cnt=0;
 for(int bit=0;bit < (1<<n);bit++){
        set<int> chk;
      rep(k,n){
         if(bit & (1<<k)){
            chk.insert(k+1);
         }
      }
      bool a=true;
      rep(i,m){
          int cntt=0;
          rep(j,k.at(i)){
              if(chk.count(s.at(i).at(j)))cntt++;
          }
          if(cntt%2!=p.at(i)){
              a=false;
              break;
          }
      }
      if(a)cnt++;
 }
 cout << cnt << endl;
}