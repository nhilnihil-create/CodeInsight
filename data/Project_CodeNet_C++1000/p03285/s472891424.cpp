#include<iostream>
using namespace std;
int main()
{
    int n, i = 0, j, k = 0;
    cin >> n;
    if(n % 4 == 0 || n % 7 == 0)
    {
        cout << "Yes";
        return 0;
    }
    while(i <= n)
    {
        int j = 0;
        while(i + j <= n)
        {
            if(i + j == n)
            {
                k++;
                cout << "Yes";
                return 0;
            }
            j = j + 7;
        }
        i = i + 4;
    }
    if(k == 0)
    cout << "No";
    else
    cout << "Yes";
    return 0;
}