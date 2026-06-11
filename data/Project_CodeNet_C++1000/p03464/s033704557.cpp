#include <bits/stdc++.h>
using namespace std;

int main(){

	long long int n, ami, ama, mi, l, r, tmp;
	vector<int> v;
  
	cin>> n;
	v.resize(n);
	for(int i=0;i<n;i++) cin>> v[i];
  
  	if(v[n-1]!=2){
      	cout<< "-1" <<endl;
      	return 0;
    }
  
  	l=1;
  	r=1000000000000000000;
  	while(r-l>1){
      	mi=(l+r)/2;
      	tmp=mi;
      	for(int i=0;i<n;i++) tmp=tmp/v[i]*v[i];
      
      	if(3<tmp) r=mi;
      	else l=mi;
    }
  	ama=l;
  
  	l=1;
  	r=1000000000000000000;
  	while(r-l>1){
      	mi=(l+r)/2;
      	tmp=mi;
      	for(int i=0;i<n;i++) tmp=tmp/v[i]*v[i];
      
      	if(1<tmp) r=mi;
      	else l=mi;
    }
  	ami=r;
  
  	if(ama<ami) cout<< "-1" <<endl;
  	else cout<< ami << " " << ama <<endl;
  
  	return 0;
}