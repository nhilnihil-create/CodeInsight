
#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    //int t=1 ; cin>>t ; while(t--)
    {
        int a, b;
        cin >> a >> b;

        cout << (b  + (b%a ==0 ? 1 : -1)*a) << '\n'; 
    }
    
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}

