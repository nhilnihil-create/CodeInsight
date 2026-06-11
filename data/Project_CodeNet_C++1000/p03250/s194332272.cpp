#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=1e5+9;
int main()
{
    FASTINOUT;
    int y[3];
    cin>>y[0]>>y[1]>>y[2];
    sort(y,y+3);
    cout<<y[2]*10+y[1]+y[0];
    return 0;
}