#include <iostream>
using namespace std;
 
int main() {
	int S[4];
	int x;
	cin>>x;
	for(int i=3;i>=0;i--)
	{ 
		S[i]=x%10;
		x=int(x/10);
		
	}
	int a=10*S[0]+S[1];
	int b=10*S[2]+S[3];
	if(((12<a && a<99)||a==0) && 0<b && b<=12)
	cout<<"YYMM";
	else if(0<a && a<=12 && ((12<b && b<=99)||b==0))
	cout<<"MMYY";
	else if(0<a && a<=12 && 0<b && b<=12)
	cout<<"AMBIGUOUS";
	else
	cout<<"NA";
	
	return 0;
}
