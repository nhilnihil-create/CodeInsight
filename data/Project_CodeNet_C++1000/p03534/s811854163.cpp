#include<iostream>
using namespace std;
int main(void){
	int a,b,c;
	string S;
	cin>>S;
	a=b=c=0;
	for (int i=0;i<S.size();++i)
		if (S[i]=='a') ++a;
		else if (S[i]=='b') ++b;
		else ++c;
	if ((a-1)*2>(b+c)||(b-1)*2>(a+c)||(c-1)*2>(a+b)) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}