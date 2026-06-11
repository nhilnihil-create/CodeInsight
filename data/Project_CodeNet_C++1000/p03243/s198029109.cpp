#include<bits/stdc++.h>
using namespace std;

int opts[] = {111,222,333,444,555,666,777,888,999};

int main(void){
	int n;
	cin>>n;
	for(int i = 0; ;i++){
		if(opts[i] >= n) {
			cout<<opts[i]<<'\n';
			break;
		}
	}
	return 0;
}
