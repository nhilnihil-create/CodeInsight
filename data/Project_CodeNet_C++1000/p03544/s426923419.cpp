#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    long long ha[n+1];
    ha[0] = 2; ha[1] = 1;

    for(int i=2; i<=n; i++) {ha[i]=0;}

    for(int i=2; i<=n; i++)
        {ha[i] = ha[i-1] + ha[i-2];}
    cout << ha[n] << endl;

    return 0;}
// done by ABO KHALED
