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
    string s;
    cin>>s;
    ll k,cur=0,lim=5000000000000000;
    cin>>k;
    for(int i=0; i<s.length(); i++)
    {
        cur++;
        if(k==cur)
        {
            cout<<s[i]<<endl;
            return 0;
        }
        else if(s[i]!='1')
        {
            cout<<s[i]<<endl;
            return 0;
        }
    }


    return 0;
}
