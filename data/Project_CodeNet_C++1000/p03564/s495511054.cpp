#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  int ans =1;
  
  while(n>0){
  	if(ans > k){
    	ans += k;
 	}else{
   	 	ans *=2;
  	}
    n--;
  }
  
  cout << ans << endl;
}