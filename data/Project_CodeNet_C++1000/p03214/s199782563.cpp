#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long int ll;

double ABS(double a,double b){
	if(a>b){
		return a-b;
	}
	else{
		return b-a;
	}
}

int main(){
	int n; cin >> n;
	vector<int> a(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	double ave=1.0*sum/n;
	vector<double> b(n);
	for(int i=0;i<n;i++){
		b[i]=ABS(ave,(double)a[i]);
	}
	int ans=-1; double mi=1e9;
	for(int i=0;i<n;i++){
		if(mi>b[i]){
			mi=b[i];
			ans=i;
		}
	}
	cout << ans << endl;
}