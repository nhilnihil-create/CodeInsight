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
typedef vector<int>  vi;
typedef vector<ll>   vll;
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
	int a,b,c,d,n,i,t,tmp,e,f,p;
	string str;
	cin>>str;
	a=str[0]-'0';
	b=str[1]-'0';
	c=str[2]-'0';
	d=str[3]-'0';
	if((a*10+b>=1&&a*10+b<=12)&&(c*10+d>=1&&c*10+d<=12))
	cout<<"AMBIGUOUS\n";
	else if((a*10+b>=1&&a*10+b<=12))
	cout<<"MMYY\n";
	else if((c*10+d>=1&&c*10+d<=12))
	cout<<"YYMM\n";
	else 
	cout<<"NA\n";
	
	return 0;
}