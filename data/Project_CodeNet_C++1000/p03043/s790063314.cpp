#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	double ret = 0;
	for(int i=1; i<=n; i++){
		double prob = 1.0/n;
		if(i>=k) ret+=prob;
		else{
			int curr = i;
			int dice = 0;
			while(curr<k){
				dice++;
				curr*=2;
			}
			double cur = 1;
			while(dice--) cur/=2;
			ret+=prob*cur;
		}
	}
	cout.precision(10);
	cout<<ret;
}