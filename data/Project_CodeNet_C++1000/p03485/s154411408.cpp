#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int a,b,ave;
  	cin >> a >> b;
  	ave=(a+b)/2.0;
    if((a+b)%2==1){
    	ave++;
    }
  	cout << ave;
}