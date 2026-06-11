#include <bits/stdc++.h>
using namespace std;

int main(){
	long n,m,c;
	long b[20];
	
	cin >>n>>m>>c;
	int counter = 0;
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		int sum = c;
		int tmp;
		for(int j=0;j<m;j++){
			cin >> tmp;
			sum+= (tmp*b[j]);
		}
		counter = (sum > 0) ? counter+1:counter;
	}
	cout << counter <<"\n";
}
