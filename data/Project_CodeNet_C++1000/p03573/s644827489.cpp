#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int main(){

	int a,b,c;
    cin>>a>>b>>c;
  	
  	if(a==b)cout<<c;
  	else if(b==c)cout<<a;
  	else cout<<b;
  	cout<<endl;

	return 0;
}
