#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector<string>v;
     map<string,ll>mp;
     map<char,ll>tap;
    char a[] = {'A','C','H','M','R'};
      do {
       string s = "" ;
       s += a[0] ;
       s += a[1] ;
       s += a[2] ;
       sort(s.begin(),s.end());
       if(!mp[s])
        v.push_back(s);
      mp[s]++;

    } while (next_permutation(a, a + 5));

    ll n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        tap[s[0]]++;
    }

    ll ans = 0 ;
    for(int i=0; i<v.size(); i++)
    {
        ll x = tap[v[i][0]];
        ll y = tap[v[i][1]];
        ll z = tap[v[i][2]];
        ans += x*y*z ;
    }


     cout << ans << endl;


}
