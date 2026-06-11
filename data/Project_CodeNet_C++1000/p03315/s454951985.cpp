#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	string a;
	cin>>a;
	int i,len,c=0;
	for(i=0; i<4; i++)
    {
        if(a[i]=='+'){c++;}
        else{c--;}
    }
    cout<<c;
}