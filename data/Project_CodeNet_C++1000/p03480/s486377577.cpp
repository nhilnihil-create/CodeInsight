#include<bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    int res = n;
    for(int i = 0; i < n; i++)
        if(s[i] != s[i+1])
            res = min(res, max(i+1, n-i-1));

    cout << res;


    return 0;
}
