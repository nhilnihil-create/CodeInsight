#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    ll ans = 0 , ans2=0;
    for(int i=0; i<s.size(); i++)
    {
        if (i%2==0)
        {
            if (s[i]=='1') ans++;
        }
        else
        {
            if (s[i] == '0') ans++;
        }
    }

    ans2 = ans;
    ans = 0;
    for(int i=0; i<s.size(); i++)
    {
        if (i%2)
        {
            if (s[i]=='1') ans++;
        }
        else
        {
            if (s[i] == '0') ans++;
        }
    }

    cout << min(ans,ans2);
	//
  
    return 0;
}