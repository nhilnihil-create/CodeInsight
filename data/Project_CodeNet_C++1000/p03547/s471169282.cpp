#include<bits/stdc++.h>
#define ll long long
const int N=100005;
using namespace std;
string s,t; 
int main(){
	cin>>s>>t;
	if(s[0]<t[0]) cout<<"<";
	else if(s[0]==t[0]) cout<<"=";
	else cout<<">";
    return 0;
}