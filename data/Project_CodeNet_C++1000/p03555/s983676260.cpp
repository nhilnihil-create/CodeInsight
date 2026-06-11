#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[4],b[4];
int main()
{
    cin>>a>>b;
    if(a[0]==b[2]&&a[1]==b[1]&&a[2]==b[0]) cout<<"YES";
    else cout<<"NO";
	   
    return 0;
}