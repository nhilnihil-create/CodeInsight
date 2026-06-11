#include<bits/stdc++.h>
using namespace std;

int main(){

	long long int n, k, tmp, ans=0, ex;
	vector<long long int> v, ma;
  	bool flag=false;
	//bitset<100> bs;
  
	cin>> n >> k;
  	v.resize(n);
  	ma.resize(50, 0);
  
	for(int i=0;i<n;i++){
      	cin>> v[i];
      	tmp=v[i];
      	for(int j=0;j<50;j++){
          	ma[j]+=tmp%2;
          	tmp=tmp>>1;
        }
    }
  
  	/*for(int i=49;i>=0;i--) cout<< ma[i] << " ";
  	cout<< endl;*/

	for(long long int i=49;i>=0;i--){
      	tmp=k;
      	tmp=tmp>>i;
      	ex=pow(2, i);
      	//cout<< ex <<endl;
      
      	if(tmp%2 && n/2<ma[i]) flag=true;
      	if(flag || tmp%2){
          	//cout<< "#";
          	ans+=ex*max(ma[i], n-ma[i]);
        }else{
          	//cout<< "$" << ex*ma[i] << " ";
          	ans+=ex*ma[i];
        }
  		//cout<< i  << " " << ans <<endl;
    }
  
  	cout<< ans <<endl;

	return 0;
}
