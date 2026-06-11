#include <bits/stdc++.h>
#include <string.h>
#define ll long long
#define pb push_back
#define vi vector<int>
#define nl endl
#define tc    \
    ll t;     \
    cin >> t; \
    while (t--)
#define fastio                       \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);                   \
    cout.tie(NULL);
using namespace std;
int main()
{
    fastio;
    int n,s=0;
    cin >> n;
    int c[n], v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
     for (int i = 0; i < n; i++)
    {
        if(v[i]-c[i]>0) s+=v[i]-c[i];
    }
    cout<<s;
}