#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long long K, A, B;
    cin >> K >> A >> B;

    long long ans = 0;
    if (B - A <= 2)
    {
        ans = 1 + K;
    }else if (B - A >= 3)
    {
        if (K >= A + 1)
        {
            ans += A;
            ans += (K - (A - 1)) / 2 * (B - A);
            ans += (K - (A - 1)) % 2;
        }else
        {
            ans = 1 + K;
        }
        
        
    }
    
    cout << ans << endl;

    return 0;
}