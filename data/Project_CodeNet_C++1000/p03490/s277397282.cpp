#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[100009];
int L=24000;
bool ch (int x, vector< int> a)
{
    memset(dp,0,sizeof(dp));
    dp [L] = 1;
    for (int i = 0 ; i < a.size(); i++)
    {
        int K = a[i];
        for (int i = 2*L; i >= max (K, 0) ; i--)
            dp[i] = max (dp[i] , dp[i-K]);
    }
    return dp[x];
}
main()
{
    string s;
    int x, y;
    cin>> s >> x >> y;
    x += L;
    y += L;
    vector < int > X,Y;
    int i=0;
    while (i<s.size() && s[i]=='F')
        x--,i++;
        i++;
        int c=0,d=0;
    for (i; i < s.size(); i++)
    {

        if (s[i] == 'T')
        {
            if (c%2 == 0)
                Y.push_back(2*d);
            else
                X.push_back(2*d);
            c++;
            d = 0;
        }
        else
        {
            d++;
        }

    }
    if (c%2 == 0)
                Y.push_back(2*d);
            else
                X.push_back(2*d);
    int xx=X.size(),yy=Y.size();
    for (int i = 0; i < xx; i++)
        x+=X[i]/2;
    for (int i = 0; i < yy; i++)
        y+=Y[i]/2;
    if(ch(x,X) && ch(y,Y)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
