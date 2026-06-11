//ThakurAnurag
//TemplateCode

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define fo2(i,a,n) for(ll i=n;i>=a;i--)
#define endl "\n"
#define sp " "
#define f first
#define s second
#define pb push_back
#define buffer ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define lower(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define upper(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
#define init(arr,val) memset(arr,val,sizeof(arr))
#define vecl(v) vector<ll> v
#define vecs(v) vector<string> v
#define vecp(v) vector < pair <ll,ll> > v

int main()
{
	ll d,n;
	cin>>d>>n;
	if(d==0){
		if(n==100)
			cout<<"101"<<endl;
		else
			cout<<n<<endl;
	}
	else if(d==1){
		if(n==100)
			cout<<"10100"<<endl;
		else
			cout<<n*100<<endl;
	}
	else{
		if(n==100)
			cout<<"1010000"<<endl;
		else
			cout<<n*100*100<<endl;
	}

	return 0;
}