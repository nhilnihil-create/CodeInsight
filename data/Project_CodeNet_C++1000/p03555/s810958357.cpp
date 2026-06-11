#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s,s2,s3,s4;
    cin >> s >> s2;
    s3=s , s4=s2;
    reverse(s3.begin() , s3.end());
    reverse(s4.begin() , s4.end());

    if (s4 == s && s3 == s2) cout << "YES\n";
    else cout << "NO\n";
//
    return 0;
}