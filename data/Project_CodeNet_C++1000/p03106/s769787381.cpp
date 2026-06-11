#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, K;
    cin >> A >> B >> K;
    int result = 1;
    int count = K;
    for (int i=max(A, B); i>1; i--)
    {
        if (A%i==0 && B%i==0)
        {
            count -= 1;
            if (count==0)
            {
                result = i;
                break;
            }
        }
    }
    cout << result << endl;
}