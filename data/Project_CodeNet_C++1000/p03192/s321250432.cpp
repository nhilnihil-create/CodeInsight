#include<bits/stdc++.h>
using namespace std;

int n,sum;

int main(){
	cin>>n;
	for(int i = 1;i <= 4;i ++){
		if(n % 10 == 2){
			sum++;
			n = n / 10;
		}else{
			n = n / 10;
		}
	}
	cout<<sum<<endl;
}
