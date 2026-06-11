#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    long long K;
    cin >> S >> K;
    int l = sizeof(S);
    int ans = 1;
    for (long long i = 0; i < K; i++)
    {
        if (S[i] == '1')
        {
            continue;
        }else
        {
            ans = S[i] - '0';
            break;
        }
        
    }
    
    cout << ans << endl;

    return 0;
}