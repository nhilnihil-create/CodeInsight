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
	vector<int> v;
    int i, input;

    cin >> i;

    for (int j = 0; j < i; j++)
    {
        cin >> input;
        v.push_back(input);
    }

    int p, count = -1;

    for (int num : v)
    {
        p = 2;
        int tmp = 0;
        while (num % p == 0)
        {
            p *= 2;
            tmp++;
        }
        if (count == 0)
        {
            break;
        }
        if (count < 0 || tmp < count)
        {
            count = tmp;
        }
    }

    cout << count << endl;
    return 0;
}


