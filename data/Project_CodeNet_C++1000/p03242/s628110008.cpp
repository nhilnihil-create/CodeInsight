#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define ld long double
#define mid (l+r)/2
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
const int maxn=100005;
int main()
{
    #ifdef local
    freopen("in.txt","r",stdin);
    #endif // local
    string s;
    cin>>s;
    for(int i=0;i<3;i++)
    {
        if(s[i]=='1') s[i]='9';
        else if(s[i]=='9') s[i]='1';
    }
    cout<<s<<endl;
}
