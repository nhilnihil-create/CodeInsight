#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> a(N);
	for(auto &i:a)cin >> i;
	
	int ans=0;
	int M= *max_element(a.begin(),a.end());
	int m= *min_element(a.begin(),a.end());
	
	if(m>=0){
		cout << N-1 << endl;
		for(int i=0;i<N-1;i++)cout << i+1 << " " << i+2 << endl;
		return 0;
	}
	if(M<0){
		cout << N-1 << endl;
		for(int i=0;i<N-1;i++)cout << N-i << " " << N-i-1 << endl;
		return 0;
	}
	if(abs(M)>=abs(m)){
		cout << 2*(N-1) << endl;
		int maxi=(int)(max_element(a.begin(),a.end())-a.begin());
		for(int i=0;i<N;i++){
			if(i==maxi)continue;
			cout << maxi+1 << " " << i+1 << endl;
		}
		for(int i=0;i<N-1;i++)cout << i+1 << " " << i+2 << endl;
		return 0;
	}else{
		cout << 2*(N-1) << endl;
		int mini=(int)(min_element(a.begin(),a.end())-a.begin());
		for(int i=0;i<N;i++){
			if(i==mini)continue;
			cout << mini+1 << " " << i+1 << endl;
		}
		for(int i=0;i<N-1;i++)cout << N-i << " " << N-i-1 << endl;
		return 0;
	}
}