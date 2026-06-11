/*  TAHMID RAHMAN
    DAMIAN FOREVER
     MATH LOVER
    NEVER GIVE UP
*/
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define GCD(a,b) __gcd(a,b);
#define endl "\n"
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define INFLL 9223372036854775807
#define debug 0
#define MAXN   100001
#define ar array
const int mxN=2e5;
const int MOD=1e9+7;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
//Don't hesitate to ask me if you don't understand my code.......Happy coding,Tahmid...;
int main()
{

    ll i,j,k=0,c1=0,c2=0;
    string s,one="10",zero="01";
    cin>>s;
    j=s.size();
    for(i=0;i<j;i++)
    {
        if(i%2==0&&s[i]=='1')
            c1++;
        if(i%2==1&&s[i]=='0')
            c1++;
    }
    cout<<min(c1,j-c1)<<endl;

}
