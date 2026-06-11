#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
      int n,gcd=1;
        cin >> n;
        int a[n+5];
        cin >> gcd;
        for(int i = 1; i<n; i++)
        {
            cin >> a[i];
            gcd=__gcd(gcd,a[i]);

        }
        cout<<gcd<<endl;


    
}
