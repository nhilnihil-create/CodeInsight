#include <bits/stdc++.h>

using namespace std;

long long niz[2500];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,z,w;
    cin>>n>>z>>w;

    for(int i = 0; i < n; i++)
        cin>>niz[i];

    long long a = abs(w-niz[n-1]);
    long long b = abs(niz[n-2] - niz[n-1]);

    long long res = max(a,b);

    if(n > 1) cout<<res;
    else cout<< abs(w-niz[n-1]);

    return 0;
}
