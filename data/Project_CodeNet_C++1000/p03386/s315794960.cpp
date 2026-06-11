#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int A, B, K;
    cin >> A >> B >> K;
    int i;
    for (i = A; i <= A + K - 1; i++)
    {
        if (i > B) return 0;
        cout << i << endl;
    }
    if (B - K + 1 > i) i = B - K + 1;
    for (; i <= B; i++)
    {
        cout << i << endl;
    }
    
    return 0;
}