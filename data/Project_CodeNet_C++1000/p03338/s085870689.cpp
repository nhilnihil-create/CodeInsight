#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = 0;
    for(int i=0; i<n-1; i++)
    {
        int dis1 = 0 , dis2 = 0;
        map<char,int>mp,dp;

        for(int j=0; j<=i; j++)
        {
            if(!mp[s[j]])dis1++;
            mp[s[j]]++;
        }
        for(int j=i+1; j<n; j++)
        {
            if(mp[s[j]] && !dp[s[j]])dis2++;
           dp[s[j]]++;
        }

        mx = max(mx,dis2);

    }
    cout << mx << endl;

}
