#include <bits/stdc++.h>
 
using namespace std;
 
#define ff              first
#define ss              second
#define ar              array
#define ll              long long
#define ld              long double
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define f(i,n)          for(int i=0;i<n;i++)
#define f1(i,n)         for(int i=1;i<=n;i++)
#define fl(i,n)         for(int i=n-1;i>=0;i--)
#define MOD             1000000007
#define pi              3.14159265
#define umii            unordered_map<int,int>
#define umci            unordered_map<char,int>
#define umsi            unordered_map<string,int> 
#define cout1(a)          cout << a << endl;
#define cout2(a, b)       cout << a << " " << b << endl;
#define cout3(a, b, c)    cout << a << " " << b << " " << c << endl;
#define cout4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;
#define cin1(a)           cin >> a;
#define cin2(a, b)        cin >> a >> b;
#define cin3(a, b, c)     cin >> a >> b >> c;
#define cin4(a, b, c, d)  cin >> a >> b >> c >> d;
#define check             cout << "check" << endl;
#define all(c)            (c).begin(),(c).end() 

void pv(vector<int>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<ll>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<double>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<string>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}
void pv(vector<bool>amount)
{
	for (auto i = amount.begin(); i != amount.end(); i++)
		cout << *i << " ";
	cout << endl;
}

class hitler
{	
	public:
		hitler()
		{
			cout1("DoneDone");
		}
		~hitler()
		{
			cout1("Crash");
		}
		void fun()
		{
			cout1("enter");
		}
	protected:
		int age=10;	
};

class mein:hitler
{
	public:
		mein()
		{
			cout1("Donebhai");
		}
		~mein()
		{
			cout1("Blast");
		}
		void printage(void)
		{
			cout1(age);
		}
};
ll sum=0;
int n;


int main()
{   ll k;
    cin>>n>>k;
    vi vec(n+1);
    f1(i,n)
    {
        cin>>vec[i];
    }
    vi dp(n+1,INT_MAX);

    dp[1] = 0;
    ll c;
	//dp[2] = abs(vec[2] - vec[1]);
    for(int i=2;i<=n;i++)
    {   
        if(i-1<k)
        {
            c=i-1;
        }
        else
        {
            c=k;
        }
        
        f1(j,c)
        {   
            if(dp[i]> dp[i-j]+abs(vec[i]-vec[i-j]))
                dp[i]=dp[i-j]+abs(vec[i]-vec[i-j]);
        }
    }
    cout1(dp[n]);
    
	

}
 