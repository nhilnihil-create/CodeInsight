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
	int n, a, b, sum = 0, tmp = 0, tmpi, tmpj;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++)
    {
        tmp = 0;
        tmpi = i;
        for (int j = 10000; j != 1; j /= 10)
        {
            tmpj = tmpi / j;
            tmp += tmpj;
            tmpi -= j * tmpj;
        }
        tmp += tmpi;

        if (a <= tmp && b >= tmp)
        {
            sum += i;
        }
    }

    cout << sum << endl;
    return 0;
}

