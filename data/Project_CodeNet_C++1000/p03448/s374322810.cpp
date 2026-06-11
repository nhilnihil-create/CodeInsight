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
	int a, b, c, x, tmp;
    int count = 0;

    cin >> a >> b >> c >> x;

    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            for (int k = 0; k <= c; k++)
            {
                tmp = i * 500 + j * 100 + k * 50;
                if (x == tmp)
                {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}

