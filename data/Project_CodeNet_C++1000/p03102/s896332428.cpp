#include<iostream>
#include<vector>

using namespace std;
 
int main(){
	long long n,m,c,ans = 0;
	vector<long long>b;
	
	cin >> n >> m >> c;

	for(int i = 0; i < m; i++){
		long long j;
		cin >> j;
		b.push_back(j);
	}

	for(int k = 0; k < n; k++){
		long long sum = 0;

		for(int l = 0; l < m; l++){
			long long a;
			cin >> a;
			sum += a * b[l];
		}

		if((sum + c) > 0){
			ans++;
		}
	}

	cout << ans << endl;
}
