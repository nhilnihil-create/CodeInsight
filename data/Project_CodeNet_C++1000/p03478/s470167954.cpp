#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int answer = 0;
    for (int i = 1; i < N + 1; ++i)
    {
        int n = i;
        int j = 1;
        int compare;
        while (n != 0)
        {
            int tenpow = 1;
            for (int k = 0; k < j; ++k)
            {
                tenpow *= 10;
            }
            compare += (n % tenpow) / (tenpow / 10);
            n -= n % tenpow;
            ++j;
        }
        if (compare >= A && compare <= B)
        {
            answer += i;
        }
        compare = 0;
    }
    cout << answer << endl;
}