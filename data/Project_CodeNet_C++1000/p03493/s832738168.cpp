#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	string s;
    cin >> s;

    int count = 0;
    for (char c : s)
    {
        if (c == '1')
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
