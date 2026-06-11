#include <iostream>
using namespace std;

int main()
{
    string S;
    cin >> S;

    int count = 0;
    for(int i = 0; i < 3; i++) {
        if(S[i] == 'o') {
            count += 1;
        }
    }

    cout << 700+count*100 << endl;

    return 0;
}