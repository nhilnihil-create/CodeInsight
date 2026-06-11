#include <bits/stdc++.h>

using namespace std;

long long niz[2100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,A,B;
    cin>>n>>A>>B;
    for(int i=1;i<=n;i++)
        cin>>niz[i];
    if(n>1)cout<<max(abs(B-niz[n]),abs(niz[n]-niz[n-1]));
    else cout<<abs(B-niz[n]);

    return 0;
}

