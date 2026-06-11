#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string n; cin>>n;
	int cnt=0;
	rep(i,4){
		if(n[i]=='2') cnt++;
	}
	cout<<cnt<<endl;
}