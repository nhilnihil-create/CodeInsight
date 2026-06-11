#include <bits/stdc++.h>
using namespace std;

int p(int x){
	int k=0;
	while(1){
		if(x==(1<<k))return x;
		else if(x<(1<<k))return (1<<k)-x;
		else k++;
	}
}

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	for(auto &i:A)cin >> i;
	
	sort(A.begin(),A.end());
	
	int ans=0;
	while(!A.empty()){
		auto last=A.end();
		last--;
		int x=*last;
		int y=p(x);
		A.erase(last);
		if(binary_search(A.begin(),A.end(),y)){
			ans++;
			auto it=lower_bound(A.begin(),A.end(),y);
			A.erase(it);
		}
	}
	cout << ans << endl;
	return 0;
}