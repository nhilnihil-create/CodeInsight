#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    if(n<1200)
        cout<<"ABC";
    else if(n>=1200 && n<2800)
        cout<<"ARC";
    else 
        cout<<"AGC";
    return 0;
}
