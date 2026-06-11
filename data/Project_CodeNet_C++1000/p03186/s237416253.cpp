#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A,B,C;
	cin>>A>>B>>C;
	cout<<min(C,A+B+1)+B<<endl;
}

