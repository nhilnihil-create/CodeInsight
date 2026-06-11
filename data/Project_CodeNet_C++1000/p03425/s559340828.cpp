#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> ans(5,0);
	vector<string> arr;
	for(long long i=0;i<n;i++){
		string a;
		cin>>a;
		if(a.at(0)=='M'){
			ans.at(0)++;
		}else if(a.at(0)=='A'){
			ans.at(1)++;
		}else if(a.at(0)=='R'){
			ans.at(2)++;
		}
		else if(a.at(0)=='C'){
			ans.at(3)++;
		}
		else if(a.at(0)=='H'){
			ans.at(4)++;
		}
		arr.push_back(a);
	}long long f=0;
	for(int i=0;i<3;i++){
		for(int j=i+1;j<4;j++){
			for(int k=j+1;k<5;k++){
					f+=ans[i]*ans[j]*ans[k];
				}
			}
	}
	cout<<f;
	return 0;
}