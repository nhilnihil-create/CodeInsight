#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n ;
    int num;
    int x=0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> num;
        while(num%2==0)
        {
            num/=2;
            x++;
        }
    }
    cout << x ;
    return 0;
}
