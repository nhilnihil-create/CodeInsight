#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=1e5+9;
int main()
{
    FASTINOUT;
    int a,b;
    cin>>a>>b;
    int y[3];
    y[0]=a-b;
    y[1]=a+b;
    y[2]=a*b;
    sort(y,y+3);
    cout<<y[2];
    return 0;
}
