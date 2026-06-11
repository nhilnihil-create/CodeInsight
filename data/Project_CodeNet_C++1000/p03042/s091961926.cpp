#include<iostream>
#define ll long long
using namespace std;
int main(int argc, char *argv[])
{
	ll a;
	cin>>a;
	if(a%100 <= 12 && a%100>0 && a/100 <= 12 && a/100 >0 )
	{
		cout<<"AMBIGUOUS"<<endl;
	}
	else if (a%100<=12 && a%100>0)
	{
		cout<<"YYMM"<<endl;
	}
	else if (a/100<=12 && a/100>0)
	{
		cout<<"MMYY"<<endl;
	}
	else cout<<"NA"<<endl;
	
	
	

	return 0;
}