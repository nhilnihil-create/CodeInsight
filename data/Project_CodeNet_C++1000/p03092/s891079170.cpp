#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=5000;
const long long oo=1e16+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int n,a[N+5];
long long A,B,f[N+5];
int main()
{
	//freopen("Rotation Sort.inp","r",stdin);
	//freopen("Rotation Sort.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin>>n>>A>>B;
    for (int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=n+1; n++;
    for (int i=1;i<=n;i++)
    {
        f[i]=oo;
        int dem1=0, dem2=0;
        for (int j=i-1;j>=0;j--)
        {
            if (a[j]<a[i]) f[i]=min(f[i],f[j]+dem1*B+dem2*A);
            if (a[j]<a[i]) dem1++; else dem2++;
        }
    }
    cout<<f[n];
	return 0;
}
