#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
#define lli                                 long long int
#define lb                                  long double
#define pi                                  acos(-1)
#define FindDistance(ax,ay,bx,by)           sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))
#define gcd(a,b)                            __gcd(a,b)
#define lcm(a,b)                           (a/gcd(a,b))*b
#define T                                  int t;cin>>t;for(int tt=1;tt<=t;tt++)
#define all(v)                             v.begin(),v.end()
#define pb                                 push_back
#define inf                                999999999999999
#define mod                                1000000007
#define maxn                               100003
#define FastIO                             ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
int main()
{
    string s;
    cin>>s;
    if(s=="A")
        cout<<"T"<<endl;
        else if(s=="T")
        cout<<"A"<<endl;
        else if(s=="G")
        cout<<"C"<<endl;
        else if(s=="C")
        cout<<"G"<<endl;

    return 0;
}
