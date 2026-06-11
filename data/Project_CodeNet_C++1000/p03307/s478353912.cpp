#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    
    int N;

    cin >> N;

    if(N % 2)
        cout << N * 2 << endl;
    else
        cout << N << endl;

    return 0;
}