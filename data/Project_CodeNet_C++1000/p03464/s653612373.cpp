#include <bits/stdc++.h>
using namespace std;

int main(){

	long long int n, mi=2, ma=3;
	vector<int> v;
  
	cin>> n;
	v.resize(n);
	for(int i=0;i<n;i++) cin>> v[i];
  	reverse(v.begin(), v.end());
  
  	if(v[0]!=2){
      	cout<< "-1" <<endl;
      	return 0;
    }
  
  	for(int i=1;i<n;i++){
        mi=(mi+v[i]-1)/v[i]*v[i];
        ma=ma/v[i]*v[i]+v[i]-1;
      
      	if(ma<mi){
          	cout<< "-1" <<endl;
          	return 0;
        }
    }
  
  	cout<< mi << " " << ma <<endl;
  
  	return 0;
}