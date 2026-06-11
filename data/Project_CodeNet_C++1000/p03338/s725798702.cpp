#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
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
    int mx=0,len;
    cin>>len>>s;

    for(int i=0; i<len; i++)
    {
        map<int,int>mp;
        int cnt=0;
        for(int j=i; j>=0; j--)
           mp[s[j]]=1;
        for(int j=i+1; j<len; j++)
            {
                if(mp[s[j]]==1)
                    mp[s[j]]=2,cnt++;

            }
        mx=max(mx,cnt);
    }
    cout<<mx<<endl;


    return 0;
}
