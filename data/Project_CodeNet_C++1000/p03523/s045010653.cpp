#include <bits/stdc++.h>
#define cinf(n,x,y,z) for(int i=0;i<(n);i++) cin >> x[i]>>y[i]>>z[i];
typedef long long int ll;
using namespace std;

int main(){
	string s; cin>>s;
	bool a= false;
	if(s == "AKIHABARA") a= true;
	if(s == "KIHABARA") a= true;
	if(s == "AKIHBARA") a= true;
	if(s == "AKIHABRA") a= true;
	if(s == "AKIHABAR") a= true;
	if(s == "KIHBARA") a= true;
	if(s == "KIHABRA") a= true;
	if(s == "KIHABAR") a= true;
	if(s == "AKIHBRA") a= true;
	if(s == "AKIHBAR") a= true;
	if(s == "AKIHABR") a= true;
	if(s == "KIHBRA") a= true;
	if(s == "KIHBAR") a= true;
	if(s == "KIHABR") a= true;
	if(s == "AKIHBR") a= true;
	if(s == "KIHBR") a= true;
	cout << (a?"YES":"NO") <<endl; 
}
