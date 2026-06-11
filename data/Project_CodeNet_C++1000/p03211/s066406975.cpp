#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin>>s;
	int m=1000000;
	for(int i=0;i<s.size()-2;i++)
	{
	    int k=(int )s[i]-48;
	    int k2=(int)s[i+1]-48;
	    int k3=(int)s[i+2]-48;
	    if(abs(k*100+k2*10+k3-753)<m)
	    {
	        m=abs(k*100+k2*10+k3-753);
	    }
	} 
	cout<<m<<endl;
	return 0;
}
