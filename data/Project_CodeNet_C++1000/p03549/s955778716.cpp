#include <bits/stdc++.h>
#include <math.h>

using namespace std;

double ruizyo(double m){
	double ret=1;
	for(double i=0;i<m;i++){
		ret*=2;
	}

	return ret;
}

int main(){
	double n,m;
	cin>>n>>m;
	double r=ruizyo(m);

	cout<<100*(n-m)*r + 1900*m*r<<endl;

	return 0;
}
