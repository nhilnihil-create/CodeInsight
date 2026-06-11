#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    if (a==b)cout<<c;
    else if (b==c)cout<<a;
    else cout<<b;
    return 0;
}
