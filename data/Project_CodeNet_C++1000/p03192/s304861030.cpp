#include<bits/stdc++.h>
using namespace std;
string s;
int ans=0;
int main()
{
	getline(cin,s);
    int chang=s.length();
    for(int i=0;i<chang;i++){
    	if(s[i]=='2') ans++;
	}
	cout<<ans;
    return 0;
}