#include <iostream>
#include <string>
using namespace std;
int main() {
    int ans = 0, len = 0;
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'A' || input[i] == 'C' || input[i] == 'G' || input[i] == 'T')
        {
            len++;
        }
        else
        {
            if (ans < len) ans = len;
            len = 0;
        }
    }
    if (ans < len) ans = len;
    cout << ans;
}