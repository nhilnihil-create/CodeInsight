#include<bits/stdc++.h>
using namespace std;

int n,sum,maks;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i = 1;i <= n;i++){
		int bil;
		cin>>bil;
		sum = sum + bil;
		if(bil > maks){
			maks = bil;
		}
	}
	cout<<sum - maks / 2<<endl;
}
