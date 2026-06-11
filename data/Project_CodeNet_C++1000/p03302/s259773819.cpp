#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a=0,b=0;
    cin>>a>>b;
    if(a+b==15)
    	cout<<"+";
    else if(a*b==15)
    	cout<<"*";
    else
    	cout<<"x";
    cout<<endl;
}