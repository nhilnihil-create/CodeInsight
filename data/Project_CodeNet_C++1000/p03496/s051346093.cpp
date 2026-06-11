#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	int amin=1e7,amax=-1e7;
	int mindex,maxdex;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if(amin>a[i]){
			amin=a[i];
			mindex=i;
		}
		if(amax<a[i]){
			amax=a[i];
			maxdex=i;
		}
	}
	cout << (n-1)*2 << endl;
	if(abs(amax)>=abs(amin)){
		for(int i=0;i<n;i++){
			if(i!=maxdex) cout << maxdex+1 << ' ' << i+1 << endl;
		}
		for(int i=0;i<n-1;i++){
			cout << i+1 << ' ' << i+1+1 << endl;
		}
	}else{
		for(int i=0;i<n;i++){
			if(i!=mindex) cout << mindex+1 << ' ' << i+1 << endl;
		}
		for(int i=0;i<n-1;i++){
			cout << n-i << ' ' << n-i-1 << endl;
		}
	}
	return 0;
}
