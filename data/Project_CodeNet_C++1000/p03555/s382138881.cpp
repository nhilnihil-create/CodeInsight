#include<bits/stdc++.h>
#define ll long long
const int N=100005;
using namespace std;
char s[5][5]; 
int main(){
	for(int i=0;i<2;i++)
	    for(int j=0;j<3;j++)
	        cin>>s[i][j];
	if(s[0][0]==s[1][2]&&s[0][1]==s[1][1]&&s[0][2]==s[1][0]) cout<<"YES";
    else cout<<"NO";
    return 0;
}