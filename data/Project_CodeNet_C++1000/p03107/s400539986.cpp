#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int lli;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli t, i, j, zc=0, oc=0;
    string s;
    cin >> s;
    for(i=0; i<s.size(); i++) {
        if(s[i]=='0') zc++;
        else oc++;
    }
    t = min(zc, oc);
    cout << t*2 << endl;
    return 0;
}