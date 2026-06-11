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
    map<string,int>mp;
    int n;
    cin>>n;
    string last,s;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        if(i)
        {
            if(mp[s])
            {
                cout<<"No"<<endl;
                return 0;
            }
            int sz=last.length();
            if(last[sz-1]!=s[0])
            {
                cout<<"No"<<endl;
                return 0;
            }

        }

        mp[s]++;
        last=s;

    }
    cout<<"Yes"<<endl;
    return 0;
}
