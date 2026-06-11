#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=1e5+9;
int main()
{
    FASTINOUT;
    int x,y,c,d;
    cin>>x>>y>>c>>d;
    if (x+y>c+d)
        cout<<"Left";
    else if (x+y<c+d)
        cout<<"Right";
    else
        cout<<"Balanced";
    return 0;
}
