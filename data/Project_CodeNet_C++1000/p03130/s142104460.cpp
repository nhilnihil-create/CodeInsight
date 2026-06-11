#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
 
   
int main(){
  VI a(6);
  rep(i,6)cin >> a.at(i) ;
  int sum=0;
  int cnt1=0;
  int cnt2=0;
  int cnt3=0;
  int cnt4=0;
  rep(i,6){
    if(a.at(i)==1)cnt1++;
    else if(a.at(i)==2)cnt2++;
    else if(a.at(i)==3)cnt3++;
    else if(a.at(i)==4)cnt4++;
  }
  if(cnt1==3 || cnt2==3 || cnt3==3 ||cnt4==3)cout << "NO" << endl;
  else cout << "YES" << endl;

} 
    