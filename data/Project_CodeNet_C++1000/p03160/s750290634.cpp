#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back
#define mkp make_pair
#define pi pair<int,int>//struct pi {int fi,se;};
#define all(v) (v).begin(), (v).end()
#define rep(i, l, r) for(int i=(int)(l);i<(int)(r);i++)
#define repd(i, l, r) for (int i=(int)(l);i>=(int)(r);i--)
#define ln length()
#define sz size()
const int N=100006;
int t[N] ;

///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        memset(t,-1,sizeof(t));
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        t[n-1] = 0;
        t[n-2] = abs(a[n-1] - a[n-2]);
        repd(i,n-3,0){
            t[i] = min(abs(a[i+1] - a[i]) + t[i+1] , abs(a[i+2] - a[i]) + t[i+2]);
        }
        cout << t[0]<<endl;

    }
}