#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long 
#define F(n) for(int i = 0; i < n; ++i)
#define Debug cout<<endl<<"I AM IRONMAN"<<endl

int main ()
{
    fastio;
    int n,a[55],b[55];
    cin >> n;
    F(n)
    {
        cin >> a[i];
    }
    F(n)
    {
        cin >> b[i];
    }
    int sum=0;
    F(n)
    {
        if(a[i]-b[i]>0)
        {
            sum=sum+(a[i]-b[i]);
        }

    }
    cout << sum;


    return 0;
}