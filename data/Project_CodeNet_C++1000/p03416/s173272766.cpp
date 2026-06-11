#include <bits/stdc++.h>
using namespace std;

int main(){
	int n1,n2,S[5],cnt=0;
	cin>>n1>>n2;
	for(int i=n1;i<=n2;i++){
		int tmp=i;
		int j=4;
		while(tmp>0){
			S[j]=tmp%10;
			tmp/=10;
			j--;
		}
		if (S[0]==S[4]&&S[1]==S[3])cnt++;
	}
	cout<<cnt<<endl;
}