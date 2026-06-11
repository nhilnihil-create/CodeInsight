#include<iostream>
#include<string>

using namespace std;
int main(int argc, char *argv[])
{
	int n,k,i;
	string s;
	cin>>n>>k;
	cin>>s;
	s[k-1]=towlower(s[k-1]);
	cout<<s<<endl;
	
	

	return 0;
}