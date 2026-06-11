#include<bits/stdc++.h>
using namespace std;
#define int            int64_t
#define double         long double
#define nitro          ios_base::sync_with_stdio(false);cin.tie(0);
#define vi             vector<int64_t>
#define pub            push_back
#define puf            push_front
#define pob            pop_back
#define pof            pop_front
#define PI             3.1415926535897932384626433832795
#define read(a)        for(auto& x : a) cin>> x
#define endl           '\n'
#define gap            ' '
#define min3(a,b,c)    min(a, min(b, c))
#define max3(a,b,c)    max(a, max(b, c))
#define MOD            1000000007
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int32_t main()
{
    nitro
    int n,m;cin>>n>>m;
    n+=2,m+=2;
    char c[n][m];
    for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
    c[i][j]='.';
    for(int i=1;i<=n-2;++i)
    for(int j=1;j<=m-2;++j)
    cin>>c[i][j];
    for(int i=1;i<=n-2;++i){
    for(int j=1;j<=m-2;++j)
    {
    	int a=0;
    	if(c[i][j]=='.')
    	{
    		if(c[i][j+1]=='#') a++;
    		if(c[i][j-1]=='#') a++;
    		if(c[i+1][j]=='#') a++;
    		if(c[i-1][j]=='#') a++;
    		if(c[i+1][j+1]=='#') a++;
    		if(c[i+1][j-1]=='#') a++;
    		if(c[i-1][j-1]=='#') a++;
    		if(c[i-1][j+1]=='#') a++;
    		cout<<a;
    	}
    	else cout<<"#";
    }
    cout<<endl;
    }
}