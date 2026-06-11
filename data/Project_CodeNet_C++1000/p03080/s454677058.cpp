#include <bits/stdc++.h>
using namespace std;

void Yes(bool f){cout<<(f?"Yes":"No")<<endl;}

signed main()
{
    int N;
    string s;

    cin >> N >> s;

    Yes(count(s.begin(), s.end(), 'R') > N/2);
}
