#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d,e,k;cin >> a >> b >> c >> d >> e >> k;
  	int mi,ma;
  	mi=min(a,min(b,min(c,min(d,e))));
  	ma=max(a,max(b,max(c,max(d,e))));
  	cout << (k>=ma-mi?"Yay!":":(");
  	return 0;
}
