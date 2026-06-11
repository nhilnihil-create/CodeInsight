#include<bits/stdc++.h>
using namespace std;

int main(){
	int num, total=0;

	cin>>num;

	while(num){
		total += (num%10);
		num = num/10;
	}

	cout<<(total == 1 ? 10 : total)<<'\n';

	return 0;
}