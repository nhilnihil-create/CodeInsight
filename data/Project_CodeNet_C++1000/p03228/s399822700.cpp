#include<bits/stdc++.h>
using namespace std;
int main(){
  	long long int a,b,k;cin>>a>>b>>k;
  	int turn = 0;
  	while(k--){
    	if(!turn){
        	int m = a/2;
          	a/=2; b+=m;
        }
      	else {
        	int m = b/2;
          	b/=2; a+=m;
        }
      	turn++;
      	turn%=2;
    }
  	cout<<a<<" "<<b;
}