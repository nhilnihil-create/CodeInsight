
#include <iostream>
using namespace std;
int N, K;
int main()
{
    cin >> N >> K;
    if (N != 0 && K != 0) {
        cout << (N % K!=0) << endl;
    }
    return 0;
}

