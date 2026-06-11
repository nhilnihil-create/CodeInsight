#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k;
cin>>n>>k;
string s;
cin>>s;
s[k-1]+=('a'-'A');
cout<<s<<endl;
}