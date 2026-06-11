#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
  int a,b,c,d,e;
  
  cin >> a >> b >> c >> d >> e;
  
 int ans = a*d+b*e;
  	for (int i=0;i<=max(d,e);i++){
      
    	ans = min (ans,a*max(0,(d-i))+b*max(0,(e-i))+c*2*i);
    }
  
  	cout << ans << endl;
}
 