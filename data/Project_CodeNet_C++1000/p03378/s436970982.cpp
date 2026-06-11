#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    int ans[m];
    for(int i = 0; i < m; i++)
        {
        cin >> ans[i];
        }
    int k = 0, t = 0;
    for(int i = 0; i < m; i++)
    {
        if(ans[i] < x)
                k++;
        else
                t++;
    }
    cout << min(t, k);
    return 0;
}