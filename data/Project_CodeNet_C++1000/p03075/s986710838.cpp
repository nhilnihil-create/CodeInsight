#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5], k;
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    cin >> k;
    for(int i = 0; i < 5; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
            if(abs(a[i] - a[j]) > k)
            {
                cout << ":(";
                return 0;
            }
        }
    }
    cout << "Yay!";
    return 0;
}
