#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
using P = pair<int,int>;
using ivec = vector<int>;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const int MOD=1000000007;
int INF=100100100100100;
int add(int a,int b){
  return (a+b)%MOD;
}
int prod(int a,int b){
  return (a*b)%MOD;
}

int beki(int a,int b)
{
	if(b==0)return 1;
	int x=beki(a,b/2);
	if(b%2==0)return (x*x)%MOD;
	else return (((a*x)%MOD)*x)%MOD;
}

int inv(int a)
{
	return beki(a,MOD-2);
}

int kaijou(int a)
{
	int ans=1;
	for(int i=1;i<=a;i++)
	{
		ans=(ans*i)%MOD;
	}			
	return ans;
}

/*int combi(int a,int b)
{
	int ret=1;
	for(int i=1;i<=b;i++)
	{
		ret=(((ret*(a+1-i))%MOD)*inv(i))%MOD;
	}
	return ret;
}*/
/*
const int MAX_a=200010;
int cb[MAX_a+1]
void combi(int a,int b)
{
    int ret=1;
    cb[0]=1;
    for(int i=1;i<=b;i++)
    {
	ret=(((ret*(a+1-i))%MOD)*inv(i))%MOD;
        cb[i]=ret;
    }
	
}*/

vector<P> prime_factorize(int N)
{
	vector<P> res;
	for(int a=2;a*a<=N;a++)
	{
		if(N%a!=0)continue;
		int ex=0;
		while(N%a==0)
		{
			ex++;N/=a;
		}
		res.push_back(P(a,ex));
	}
	if(N!=1)res.push_back(P(N,1));
	return res;
}

//ここから書く
int S(int n){
  if(n<10)return n;
  return S(n/10)+(n%10);
}
int nine(int n){
  if(n%10!=9)return 1;
  return nine(n/10)*10;
}
signed main(){
  int k;cin>>k;
  ivec bek(20);bek[0]=1;
  rep(i,17)bek[i+1]=bek[i]*10;
  
  int cnt=0;
  rep(i,15){
    int sa=1;
    if(i>=3)sa=bek[i-3];
    for(int n=bek[i]+sa-1;n<bek[i+1];n+=sa){
      if(cnt>=k)return 0;
      if(n<=S(n)*nine(n)){
        cout<<n<<endl;
        cnt++;
      }
    }
  }
  return 0;
}