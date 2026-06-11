#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    int x;
    cin >> x;
    int ans = 1;
    for (int i = 2; i < 50; i++)
    {
        int temp = i*i;
        while(temp <=x)
        {
            ans = max(ans,temp);
            temp *= i;
        }
    }
    cout << ans << endl;
    
}