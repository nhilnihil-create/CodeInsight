#include <bits/stdc++.h>
using namespace std;




int main(){
	int N;
	cin>>N;
	
	long long ans = 0;
	vector<int> A;
	vector<int> B;
	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		A.push_back(a);
		B.push_back(b);
	}
	if(A==B){
		cout<<0<<endl;
		return 0;
	}
	vector<int> x;
	for(int i=0;i<N;i++){
		if(A[i]<=B[i]){
			ans = (long long)ans+B[i];
		}
		else{
			x.push_back(B[i]);
		}
	}
	
	sort(x.begin(),x.end(),greater<int>());
	
	for(int i=0;i<x.size()-1;i++){
		ans=(long long)ans+x[i];
	}
	
	
	cout<<ans<<endl;
	
	return 0;
}
