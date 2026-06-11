#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
   int n;
   string s;
   cin >> n >> s;
   int ee=0;
   VI e(n);
   int ww=0;
   VI w(n);
   rep(i,n){
      if(s.at(i)=='W')ww++;
      if(s.at(i)=='E')ee++;
      e.at(i)=ee;
      w.at(i)=ww;
   }
   VI cnt(n);
   rep(i,n){
      if(i==0){
         cnt.at(i)=w.at(n-1)-w.at(0);
      }
      else if(i==n-1){
         cnt.at(i)=e.at(n-2);
      }
      else{
         cnt.at(i)=e.at(i-1)+w.at(n-1)-w.at(i);
      }
   }
   sort(cnt.begin(),cnt.end());
   int x=cnt.at(n-1);
   cout << n-x-1 << endl;

}
    