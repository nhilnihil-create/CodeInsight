#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i=0; i<=25; i++){
		for(int j=0; j<=15; j++){
			if(4*i + 7*j == n){
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}