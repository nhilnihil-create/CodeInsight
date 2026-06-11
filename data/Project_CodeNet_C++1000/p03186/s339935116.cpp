#include<bits/stdc++.h>	
using namespace std;
int main(){
	int A, B, C, D;
	cin>>A;
	cin>>B;
	cin>>C;
	if(A+B>=C|| B>C){
		D=B+C;
	}else if(A+B<C){
		D=2*B+A+1;
	}
	cout<<D<<endl;
} 