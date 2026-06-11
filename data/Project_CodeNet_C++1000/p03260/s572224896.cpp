#include <iostream>

using namespace std;

void solve(int a, int b)
{
    int ans, count = 0;

    for (int n = 1; n <= 3; n++)
    {
        ans = a * b * n;
        
        if(ans%2 != 0)
        {
            count++;
        }
    }
    
    if(count > 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

int main()
{
    int a, b;

    cin >> a >> b;

    solve(a, b);

    return 0;
}