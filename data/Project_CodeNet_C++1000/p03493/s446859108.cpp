#include <iostream>
using namespace std;

int main()
{
    char s;
    int count;

    count = 0;
    for(int i = 0; i < 3; i++) {
        cin >> s;
        if(s == '1') {
            count += 1;
        }
    }

    cout << count << endl;
    return 0;
}