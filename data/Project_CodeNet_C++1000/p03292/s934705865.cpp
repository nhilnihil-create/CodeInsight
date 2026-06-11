#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;cin >> a >> b >> c;
  	int ans=abs(a-b)+abs(b-c)+abs(a-c);
  	cout << ans-max(abs(a-b),max(abs(b-c),abs(a-c)));
  	return 0;
}
