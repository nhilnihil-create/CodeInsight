#include<bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin >> n ;
	int p[n] , q[n];
  	for(int i = 0 ; i < n ; ++i)
    	cin >> p[i] , q[p[i]-1] = i;
  	int ans = 1 , cur = 1 ; 
	for(int i = 1 ; i < n ; ++i){
    	if(q[i] > q[i-1]) cur++;
      	else cur = 1;
      	ans = max(ans , cur);
    }
  	cout << n - ans ;
}