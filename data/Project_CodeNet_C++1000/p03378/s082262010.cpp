#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,x;
    cin >> n >> m >> x;

    vector<int> a(n,0);
    for(int i=0;i<m;i++){
        int buf;
        cin >> buf;
        a[buf-1]=1;
    }

    int cost0=0;
    int costn=0;
    for(int i=0;i<x;i++) cost0+=a[i];
    for(int i=x;i<n;i++) costn+=a[i];
    cout << min(cost0,costn) << endl;
}