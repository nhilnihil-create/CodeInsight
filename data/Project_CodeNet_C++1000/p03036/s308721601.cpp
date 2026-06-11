#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define eb emplace_back
#define precision(n) cout << fixed << setprecision(n);
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
int main()
{
    int r,d,x;
    cin>>r>>d>>x;
    int p=10;
    while(p--)
    {
        int q=r*x-d;
        cout<<q<<endl;
        x=q;
    }
    return 0;
}


