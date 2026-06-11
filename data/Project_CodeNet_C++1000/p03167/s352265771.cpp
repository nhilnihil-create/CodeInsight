#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define ld long double
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,a) REP(i,0,a)
#define REV(i,a,b) for(i=a-1;i>=b;i--)
#define rev(s) reverse(s.begin(),s.end())
#define pb push_back
#define mp make_pair
#define ord(v) sort(v.begin(),v.end());
const ll MAXN=2*1e5+10;
#define MAX 2*1e9
#define fi first
#define se second
#define pi 3.141592653589793238
#define rem 1000000007
#define eps 1e-9
// fflush(stdout);
//lower_bound,upper_bound,equal_range
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int h,w;
    cin>>h>>w;
    int m = 1000000007;
    char v[h+1][w+1];
    for(int i=0;i<h;i++)
    {
    	for(int j=0;j<w;j++)
    	{
    		cin>>v[i][j];
    	}
    }
    int A[h][w];
    for(int i=0;i<h;i++)
    {
    	for(int j=0;j<w;j++)
    	{
    		if(v[i][j]=='#'){
    			A[i][j]=0;
    		}
    		else
    		{
    			if(i==0&&j==0)A[i][j]=1;
    			else if(i==0){
    				A[i][j]=A[i][j-1];
    			}
    			else if(j==0){
    				A[i][j]=A[i-1][j];
    			}
    			else
    			{
    				A[i][j] = (A[i][j-1]+A[i-1][j])%m;
    			}
    		}
    	}
    }
    cout<<A[h-1][w-1];
	return 0;
}
