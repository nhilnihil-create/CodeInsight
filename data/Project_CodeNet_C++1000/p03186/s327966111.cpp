#include<bits/stdc++.h>
using namespace std;

long long UA,TA,TP;
long long wyn;

int main(){
	cin>>UA>>TA>>TP;
	int k = min(TA, TP);
	wyn += 2*k;
	TP -= k;
	TA -= k;
	//cout<<wyn<<endl;
	//cout<<UA<<" "<<TA<<" "<<TP<<endl;
	k = min(UA, max(TA,TP));
	wyn += k;
	TA -= k;
	TP -= k;
	UA -= k;
	TA = max(TA , (long long)0);
	TP = max(TP , (long long)0);
	UA = max(UA , (long long)0);	
	if(TP > 0) wyn += 1;
	cout<<wyn<<endl;
	return 0;
}
