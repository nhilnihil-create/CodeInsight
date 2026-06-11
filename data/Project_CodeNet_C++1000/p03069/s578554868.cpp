#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
int n;	cin>>n;
		string sd;cin>>sd;
		int mi=INT_MAX,f=0;
		int z=0,o=0;
	for(int i=0;i<sd.length();i++)
	{
	if(sd[i]=='.')z++;
	else o++;
	}

	mi=min(mi,min(z,o));
	int one=0,zero=0;
	for(int i=0;i<sd.length();i++)
	{
		if(sd[i]=='#')one++;
		else zero++;
		
		mi=min(mi,one+z-zero);
	}
	cout<<mi<<"\n";
	
	
	
	
	
}
	
	
	