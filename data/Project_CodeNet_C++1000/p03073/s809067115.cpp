#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


   
int main(){
  string s;
  cin >> s;
  int n=s.size();
  int ans1=0;
  int ans2=0;
  int ans;
  rep(i,n){
   if((i+1)%2==1){
     if(s.at(i)!='0')ans1++;
     else if(s.at(i)!='1')ans2++;
   }
   else{
     if(s.at(i)!='1')ans1++;
     else if(s.at(i)!='0')ans2++;
   }
  }
  ans=min(ans1,ans2);
  cout << ans << endl;
}