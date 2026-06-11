//Target for Pupil
//Implementation and Data structures
//Prodip sarker(student_ip)
#define bn begin()
#define en end()
#define mx 5000010
#define pb push_back
#define PI (2.0*acos(0.0))
#define al(a) a.begin(),a.end()
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rep(a,b) for(int a=0;a<b;++a)
#define fastio ios::sync_with_stdio(false)
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
	int a,b,c,n,i,t,tmp,d,e,f,p;
	string str;
	cin>>n>>a;
	cin>>str;
	for(i=0;i<n;i++)
	{
		if(a-1==i)
		cout<<(char)((str[i]-'0'+32)+'0');
		else 
		cout<<str[i];
	}
	return 0;
}