#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int A,B,C,K;
	cin>>A>>B>>C>>K;
	if(K&1)	cout<<B-A<<endl;
	else	cout<<A-B<<endl;
}
