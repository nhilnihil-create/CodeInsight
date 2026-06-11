#include <bits/stdc++.h>
using namespace std;
int main(){
	long long N,m,suma=0,cont=0;
	cin>>N;
	for(m=1;m*m<N;m++){
		if(N%m==0 && (N/m-1)!=m){
		suma+=(N/m)-1;
		}
	}
	if(suma==1) suma=0;
	cout<<suma<<endl;
}
