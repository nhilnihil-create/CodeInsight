#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<long long> a(N);
	for(int i=0; i<N; i++){
		cin >> a.at(i);
	}
	int cnt = 0;
	int ans = 0;
	for(int i=0; i<N; i++){
		if( a.at(i)%2 != 0 ){
		}
		else{
			for( ; ; ){
				if( a.at(i)%2 == 0 ){
					a.at(i) /= 2;
					ans++;
				}
				else{
					break;
				}
			}
		}	
	}
	cout << ans << endl;
	return 0;
	
}
