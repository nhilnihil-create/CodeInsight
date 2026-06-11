#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<long long> A(N);
	vector<long long> B(N);
	bool flag=true;
	for(int i=0;i<N;i++){
		cin >> A[i] >> B[i];
		if(A[i]!=B[i])flag=false;
	}
	if(flag){
		cout << "0" << endl;
		return 0;
	}
	
	long long ans=accumulate(A.begin(),A.end(),0LL),tmp=9999999999999LL;
	for(int i=0;i<N;i++){
		if(A[i]>B[i])tmp=min(tmp,B[i]);
	}
	ans-=tmp;
	cout << ans << endl;
	return 0;
}