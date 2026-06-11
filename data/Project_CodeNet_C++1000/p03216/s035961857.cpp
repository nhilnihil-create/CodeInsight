
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
//#define x real()
//#define y imag()
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=210,M=20500;

int n;
char a[1000005];
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
input;

cin>>n;
forr(i,1,n) cin>>a[i];


int q,x;
cin>>q;
while(q--)
{
    cin>>x;
    ll ans=0,ck=0,d=0,m=0,c=0;
    forr(i,1,n)
    {
        if(c>=x)
        {
            if(a[i-x]=='D')ck-=m,d--;
            else if(a[i-x]=='M')m--;

        }
        if(a[i]=='D')d++;
        else if(a[i]=='M')ck+=d,m++;
        else if(a[i]=='C')ans+=ck;
        c++;
    }
    cout<<ans<<endl;

}
return 0;
}
