#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    int n,k;
    cin >> n >> k;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (ans*2<ans + k)
        {
            ans*=2;
        }
        else
        {
            ans += k;
        }
        
    }
    cout << ans << endl;
}