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
    int len,k;
    cin>>len>>k;
    cin>>s;
    int cnt=1,f=s[0]-'0';
    vector<int>v;
    int x=0,y=0,ans=0;
    for(int i=1; i<len; i++)
    {
        if(s[i]-'0'!=f)
        {
            if(f)
            {
                x=max(x,cnt);
                v.push_back(cnt);
            }
            else
            {
                y=max(y,cnt);
                v.push_back(cnt*-1);
            }
            cnt=0;
            f^=1;
        }
        cnt++;

    }
    if(f)
    {
        x=max(x,cnt);
        v.push_back(cnt);
    }
    else
    {
        y=max(y,cnt);
        v.push_back(cnt*-1);
    }
    int l=0,r=0;
    ans=x;
    if(k)
        ans=max(ans,y);
    int sz=v.size(),tk=0,cur=0;
    while(l<sz)
    {
        while(v[l]<0 && tk==k)
        {
            cur-=abs(v[r]);
            if(v[r]<0)
                tk--;
            r++;
        }
        cur+=abs(v[l]);
        if(v[l]<0)
            tk++;
        ans=max(ans,cur);
        l++;

    }
    cout<<ans<<endl;




    return 0;
}
