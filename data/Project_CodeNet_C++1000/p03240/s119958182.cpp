#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
#define RAP(i, n) for(ll i=0;i<(n);i++)
#define FOR(i, a, b) for(ll i=(a);i<(b);i++)

#include <iostream>
#include <vector>
using namespace std;

//重複順列
vector<ll> buf;
void permutation(ll i, const ll size, const ll range_start, const ll range_end)
{
    if (i == size) {
      // ここで所望の作業を行う
      for(ll itr:buf){
        cout << itr;
      }
    }
    else{
        for(ll j = range_start; j <= range_end; ++j){
            buf[i] = j;
            permutation(i + 1, size, range_start, range_end);
        }
    }
}
int main(void)
{
 ll n, x, y, h, ansx, ansy, ansh;
 cin >> n;
 vector<ll> X(n), Y(n), H(n);
 RAP(i, n){
   cin >> X[i] >> Y[i] >> H[i];
 }
 bool flag = true, checkflag;
 RAP(i, n){
   if(H[i] != 0){
     flag = false;
     h = H[i];
     x = X[i];
     y = Y[i];
     break;
   }
 }
 RAP(i, 101){
     RAP(j, 101){
       checkflag = true;
       ansx = i;
       ansy = j;
       ansh = h + abs(x-i) + abs(y-j);
       RAP(check, n){
         if(H[check] != max(ll(0), ansh - abs(X[check]-ansx) - abs(Y[check]-ansy))){
           checkflag = false;
         }
       }
       if(checkflag){
         cout << ansx << " " << ansy << " " << ansh << endl;
         return 0;
       }
     }
   }
 return 0;
}
