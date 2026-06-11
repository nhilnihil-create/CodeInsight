#include <bits/stdc++.h>
using namespace std;

long long A,B,C;

int main(){
	cin>>A>>B>>C;
	if(C<=A+B+1){
		cout<<B+C<<'\n';
	}else{
		cout<<B+A+B+1<<'\n';
	}
}