#include <bits/stdc++.h>

using namespace std;

int main(){
 int n;
  cin >> n;
 vector<int> a(n);
  int ave=0;
  for(int i=0;i<n;i++){
   cin >> a[i];
    ave+=a[i];
  }
  
  int res;
  int dis=1000000;
  for(int i=n-1;i>=0;i--){
  
   if(dis>=abs(n*a[i]-ave)){
    dis=abs(n*a[i]-ave);
    res=i;
   }
  
  
  }
  
   cout << res << endl;
}