#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
ll N[maxn];
int main()
{
	int a,b,c;cin>>a>>b>>c;
	if((c>=a&&c<=b)||(c<=a&&b<=c)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl; 
 } 