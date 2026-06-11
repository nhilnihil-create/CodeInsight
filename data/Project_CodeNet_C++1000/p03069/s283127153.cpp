#include<iostream>
#include<functional>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bitset>
#include <sstream>
#include<queue>
#include<set>
#include<iomanip>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef unsigned long long ll;
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int bc=0;
    int wc=0;
    rep(i,n)
    {
        if(s[i]=='.')wc++;
    }
    int ans=wc;
    rep(i,n)
    {
        if(s[i]=='#')
        {
            bc++;
        }
        else
        {
            wc--;
        }
        ans=min(ans,bc+wc);
        
    }
    cout<<ans;
}