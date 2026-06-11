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
   int cntr=0;
   int cntb=0;
   rep(i,n){
       if(s.at(i)=='R')cntr++;
       else if(s.at(i)=='B')cntb++;
   }
   if(cntr>cntb)cout << "Yes" << endl;
   else cout << "No" << endl;

}