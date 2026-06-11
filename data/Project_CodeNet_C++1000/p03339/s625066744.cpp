#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pref[300010];
int suff[300010];
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=1; i<n; i++)
    {
        if(s[i-1]=='W')pref[i] = pref[i-1] + 1;
        else pref[i] = pref[i-1];
    }
    for(int i=n-2; i>=0; i--)
    {
        if(s[i+1]=='E')suff[i] = suff[i+1]+1;
        else suff[i] = suff[i+1];
    }
    int mn = INT_MAX;

    for(int i=0; i<n; i++)
    {
        mn = min(mn,suff[i]+pref[i]);
    }
    cout << mn << endl;
}
