#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int c=0;
    for(int i=0;i<s.size();i++){
	if(s[i]=='o')
	    ++c;
    }
    int rem = 15-s.size();
    int req = 8-c;

    if(req>rem)
	cout<<"NO"<<endl;
    else
	cout<<"YES"<<endl;
}
