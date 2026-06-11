#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int len;
    string s;
    cin>>s;
    len=s.length();
    int l=0,r=len+1;
    while(r-l>1)
    {
        int k=(l+r)>>1,f=1;
        for(int i=len-k; i<k-1; i++)
        {
            if(s[i]!=s[i+1])
                f=0;
        }
        if(f)
            l=k;
        else
            r=k;
    }
    cout<<l<<endl;

    return 0;
}
