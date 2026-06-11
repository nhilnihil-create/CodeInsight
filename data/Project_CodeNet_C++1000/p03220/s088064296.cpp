#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    double t,a;
    cin>>n>>t>>a;
    int x[n];
    double b[n];
    int min_idx = 0;
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        b[i]=abs((t-x[i]*0.006)-a);
        if(b[min_idx] > b[i])
            min_idx = i;
    }
    cout << min_idx + 1 << endl;
    return 0;
}