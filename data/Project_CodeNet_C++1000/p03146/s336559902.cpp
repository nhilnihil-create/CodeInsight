#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
	ll s=0,counter=0;
	cin>>s;
	while(s!=4 && s!=2 && s!=1)
	{ if(s%2==0)
	s=s/2;
else
s=3*s+1;
counter++;
		}
cout<<counter+4;
	
		
        
        
    }

    return 0;
}
