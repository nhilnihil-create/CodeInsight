#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; 
    cin >>n >>m;
    int x=0,y=1e5+1;
    for(int i=0; i<m; i++)
    {
        int l,r; cin >>l >>r;
        if(l>x) x=l;
        if(r<y) y=r;
    }
    cout <<(x<=y?y-x+1:0);
    return 0;
}
