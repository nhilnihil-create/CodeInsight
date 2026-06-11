#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=1e5+9;
int main()
{
    FASTINOUT;
    int x;
    cin>>x;
    if (x<1200)
        cout<<"ABC";
    else if (x<2800)
        cout<<"ARC";
    else
        cout<<"AGC";
    return 0;
}
