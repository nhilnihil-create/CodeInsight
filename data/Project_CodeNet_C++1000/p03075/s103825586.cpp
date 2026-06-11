#include <bits/stdc++.h>
using namespace std;

int main()
{
    int abcde[5];
    int k;
    for (int i = 0; i < 5; i++)
    {
        cin >> abcde[i];
    }
    cin >> k;

    bool ans = true;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if(abcde[j] - abcde[i] > k)ans = false;
        }
    }
    
    if(ans)cout << "Yay!" << endl;
    else cout << ":(" << endl;
}