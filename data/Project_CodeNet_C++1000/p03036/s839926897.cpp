#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
/*int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
//	for(int i=0;i<n;i++) cout<<a[i];
	int sum=0;
	for(int i=n-1;i>1;i--)
	{
		for(int j=i-1;j>0;j--)
		{
			if(a[i]==a[j]) continue;
			for(int k=j-1;k>=0;k--)
			{
				if(a[k]!=a[i] and a[k]!=a[j] and a[i] < (a[k] + a[j])) 
				{
					sum++;
				}
				
				if(a[k]!=a[i] and a[k]!=a[j] and a[i] >= (a[k] + a[j])) 
				{
					break;
				}
				
			}
		}
	}
	
	cout<<sum;
}

int main()
{
	int n,d,ans=0;
	cin>>n>>d;
	while(n--)
	{
		int a,b; cin>>a>>b;
		long long int fl=a*a + b*b;
		float sum=sqrt(fl);
		if(sum<=d) ans++;
		
	}
	cout<<ans;
}
int main()
{
	int n,k; cin>>n>>k;
	int a[n],sum=0;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<k;i++) sum+=a[i];
	cout<<sum; 
}

int main()
{
	int n,k; cin>>n>>k;
	k%2==0 and k>=2*n and k<=4*n ? cout<<"Yes" : cout<<"No";
}

int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	unsigned long long ans=1,ANS;
	vector<int>v;
	for(int i=0;i<n;i++)
	{
		ans*=a[i];
		ANS=ans;
		while(ANS)
		{
			v.push_back(ANS%10);
			ANS/=10;
		}
		if(v.size()>1000000000000000000)
		{
			cout<<"HRE";
			cout<<"-1";
			return 0;
		}
		v.clear();
	}
	cout<<ans;
}

int main()
{
	int n; cin>>n;
	string s; cin>>s;
	if(s.size()<=n) cout<<s;
	else {
		
	for(int i=0;i<n;i++) cout<<s[i];
	cout<<"...";
}}

int main()
{
	long long int a,b,c,d; cin>>a>>b>>c>>d;
	long long int sum=0,count=0;
	if(a<=d)
	{
		sum+=a;
		d-=a;
		if(d==0)
		{
			cout<<sum;
			return 0;
		}
	}
	else 
	{
		cout<<d;
		return 0;
	}
	
		if(b<=d)
	{
		
		d-=b;
		if(d==0)
		{
			cout<<sum;
			return 0;
		}
	}
	else 
	{
		cout<<d;
		return 0;
	}
	
		if(c<=d)
	{
		sum-=c;
		d-=c;
		if(d==0)
		{
			cout<<sum;
			return 0;
		}
	}
	else 
	{
		cout<<sum-d;
		return 0;
	}
	
	
}


int main()
{
	int n,k; cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++) a[i]=0;
	while(k--)
	{
		int d; cin>>d;
		for(int i=0;i<d;i++) 
		{
			int x; cin>>x;
			a[x-1]++;
		}
	}
	//cout<<a[2];
	int ans=0;
	for(int i=0;i<n;i++) if(a[i]==0) ans++; cout<<ans;
}
int main()
{
	long long int n,year=0; cin>>n;
	int a=100;
	while(a<n)
	{
		float aa=(1.0/100)*a;
		a+=floor(aa);
		year++;
	}
	cout<<year;
}
int main()
{
	long long int n,m; cin>>n>>m;
	long long int sum=0,a[n];
	for(long long int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];	
	} 
	sort(a,a+n,greater<int>());
	float min=sum*1.0/(4*m);
	a[m-1]<min?cout<<"No": cout<<"Yes\n";	
}

int main()
{
	int n; cin>>n;
	long long sum=(n/500)*1000 + ((n-(n/500)*500)/5)*5;
	cout<<sum;
}

int main()
{
	string s; cin>>s;
	
	if(s.size()%2==0) 
	{
		cout<<"No";
		return 0;
	}
	
	if(s.size()==3) 
	{
		cout<<"Yes";
		return 0;
	}
	int si=s.size()/2;
	for(int i=0;i<si/2;i++)
	{
		if(s[i]!=s[si-i-1]) 
		{
			cout<<"No";
			return 0; 
		}
	}
	int aa=s.size();
	for(int i=si+1;i<si+si/2+1;i++)
	{
		if(s[i]!=s[aa-1]) 
		{
			cout<<"No";
			return 0;
		}
		aa--;
	}
	
	cout<<"Yes";
}


int main()
{
	long long int n,a,b; cin>>n>>a>>b;
	long long int sum=n/(a+b)*a;
	n=n%(a+b);
	if(n<=a) sum+=n;
	else sum+=a;
	cout<<sum;
}
int main()
{
	int a[3][3];
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin>>a[i][j];
	int n; cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int b;
		cin>>b;
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(a[i][j]==b) a[i][j]=0;
	} 
	bool u=false;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]!=0) break;
			if(j==2) u=true;
		}
	}
	
	if(u) 
	{
		cout<<"Yes";
		return 0;
	}
	
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<3;i++)
		{
			if(a[i][j]!=0) break;
			if(i==2) u=true;
		}
	}
	
	if(u) 
	{
		cout<<"Yes";
		return 0;
	}
	
	if(a[2][0] == 0 and a[1][1] == 0 and a[0][2] == 0) 
	{
		cout<<"Yes";
		return 0;
	}
	
		if(a[0][0] == 0 and a[1][1] == 0 and a[2][2] == 0) 
	{
		cout<<"Yes";
		return 0;
	}
	
	cout<<"No";
}
int main()
{
	int a,b,B,sum=1; cin>>a>>b;
	B=b;
	while(b<=a)
	{
		b*=B;
		sum++;
	}
	
	cout<<sum;
}


		if(a[0][0] == 0 and a[1][1] == 0 and a[2][2] == 0) 
	{
		cout<<"Yes";
		return 0;

		
		
int main()
{
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(a[i]&1) continue;
		if(a[i]%3!=0 and a[i]%5!=0) 
		{
		//	cout<<a[i]<<" "<<a[i]%3<<"\n";
			cout<<"DENIED"; return 0;
		}
	}
	
	cout<<"APPROVED";
}

int main()
{
	string s; cin>>s;
	for(int i=0;s[i];i++) cout<<"x";	
}

int main()
{
	int a,n,sum=0; cin>>a>>n;
	int aa[n];
	for(int i=0;i<n;i++) {
	cin>>aa[i];
	sum+=aa[i];
	}
	sum>=a?cout<<"Yes": cout<<"No";
		
}

int main()
{
	int a,b; cin>>a>>b;
	for(int i=0;i<max(a,b);i++) cout<<min(a,b); 
}
int main()
{
	int n,sum=0,m,x; cin>>n>>m>>x;
	int a[n-1];
	for(int i=0;i<n-1;i++) 
	{
		cin>>a[i];
		sum+=a[i];
	}	
	(sum+m)<(n*x)?cout<<-1:(((n*x)-sum)<0?cout<<"0" : cout<<(n*x)-sum);
}
int main()
{
	int n; cin>>n;
	string s,ss="ABC"; cin>>s;
	int ans=0;
	auto found=s.find(ss);
	while(found!=string::npos)
	{
		ans++;
		found=s.find("ABC",found+1,3);
	}
	cout<<ans;
		
}

int main()
{
	long long int a,b,c; cin>>a>>b>>c;
	(c<=a)?cout<<a-c<<" "<<b:cout<<"0 "<<b-(c-a);
}

int main()
{
	int n; cin>>n;
	string s,ss; cin>>s>>ss;
	for(int i=0;i<n;i++) 
	{
		cout<<s[i]<<ss[i];
		}	
}
int main()
{
	int a=0;
	string s; cin>>s;
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i]) a++;
		}	
		cout<<a;
}

int main()
{
	int n; cin>>n;
	int a[n],sum=0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[i-1]) 
		{
			sum+=a[i-1]-a[i];
		a[i]=a[i-1];	
		}
	}
	cout<<sum;
	}	
	
int main()
{
	long long int a,b,c; cin>>a>>b>>c;
	a=abs(a)
	if(a/c >= b) 
	{
		cout<<a-(b*c); return 0;
	}
	b=b-(a/c);
	a=a%c;
	b&1?cout<<abs(a-c):cout<<a;
}

int main()
{
	int n,m; cin>>m; 
	m%=26;
	string s; cin>>s;
	for(int i=0;s[i];i++) 
	{
		n=s[i];
		n+=m;
		if(n<=90)
		{
			cout<<char(n);	
		}	
		else
		{
			n-=90;
			cout<<char(64+n);
		}
	}	
	
}

int main()
{
	int n; cin>>n;
	string s; cin>>s;
	int si=s.size();
	if(si&1) 
	{
		cout<<"No";
		return 0;
	}
	for(int i=0;i<si/2;i++)
	{
			if(s[i]!=s[si/2 + i])
			{
				cout<<"No";
				return 0;
			}
		
	}
	cout<<"Yes";
	return 0;
}

int main()
{
	int n; cin>>n;
	((n%1==0 and n/1 <= 9) or (n%2==0 and n/2 <= 9) or (n%3==0 and n/3 <= 9) or (n%4==0 and n/4 <= 9) or (n%5==0 and n/5 <= 9) or (n%6==0 and n/6 <= 9) or (n%7==0 and n/7 <= 9) or (n%8==0 and n/8 <= 9) or (n%9==0 and n/9 <= 9)) ? cout<<"Yes" : cout<<"No";
}

int main()
{
	int n,k; cin>>n>>k;
	int a[n],sum=0;
	
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		if(a[i]>=k) sum++;	
	}
	cout<<sum;
	
}

int main()
{
	string s; cin>>s;
	for(int i=0;s[i];i+=2)
	{
		if(s[i]=='L')
		{
			cout<<"No";
			return 0;
		} 
	}
	
		for(int i=1;s[i];i+=2)
	{
		if(s[i]=='R')
		{
			cout<<"No";
			return 0;
		} 
	}
	cout<<"Yes";
}

int main()
{
	int n; cin>>n;
	int a[n],b[n],c[n-1];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n-1;i++) cin>>c[i];
	
	int sum=b[a[0]-1];
	
	for(int i=1;i<n;i++)
	{
		sum+=b[a[i]-1];
		if(a[i]-a[i-1]==1) sum+=c[a[i-1]-1];
	}
	cout<<sum;
}

int main()
{
	int a,b; cin>>a>>b;
	cout<<(b+a-1)/a;
}

int main()
{
	int n; cin>>n;
	float sum=0;
	
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		float aa=1.0/a;
		
		sum+=aa;
	}
	
	float ans=1/sum;
	cout<<ans;
}

int main()
{
	int a,b; cin>>a>>b;
	for(int i=b-a+1;i<=b+a-1;i++) cout<<i<<" ";
}

int main()
{
	int n,sum=0; cin>>n;
	if(n==100000) cout<<90909;
	else if(n>=10000) cout<<(n-9999)+909;
	else if(n>=1000) cout<<909;
	else if(n>=100)  cout<<n-99 + 9;
	else if(n>=10) cout<<9;
	else cout<<n;
}

int main()
{
	int n,sum=0; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		if(a[i]!=(i+1)) sum++;	
	}
	sum<=2?cout<<"YES":cout<<"NO";
	
}

int main()
{
	int a,b; cin>>a>>b;
	float c=(a-b-1)*(1.0)/(b*2+1);
	c*=100;
	int d=c;
	d%100 < 50 ?cout<<d/100 + 1:cout<<d/100 + 2;
}*/

int main()
{
	int x,y,count=10;
	long long ans; cin>>x>>y>>ans;
	while(count--)
	{
		ans=x*ans-y;
		cout<<ans<<"\n";
	}
}
