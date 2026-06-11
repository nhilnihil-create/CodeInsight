#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ll long long int
#define py printf("Yes\n")
#define pn printf("No\n")
#define in cin>>
using namespace std;
const int INF = 1001001001;

int main()
{
    int a,b;
    string s;
    in a>>b>>s;
    bool flag=true;
    rep(i,s.size())
    {
        if(i!=a&&s[i]=='-')flag=false;
        if(s[a]!='-')flag=false;
    }
    if(flag)py;
    else pn;
}
