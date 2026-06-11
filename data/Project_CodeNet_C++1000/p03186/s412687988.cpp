#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll A,B,C;
	cin>>A>>B>>C;
	if(C-A-B>1){
		cout<<(C+B)-(C-A-B)+1<<endl;
	}else cout<<B+C<<endl; 
} 