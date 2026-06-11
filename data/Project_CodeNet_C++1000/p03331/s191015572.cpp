#include <iostream>

using namespace std;

unsigned digits_sum(unsigned n);

int main(int argc, char const *argv[])
{
    unsigned N, minor;

    cin >> N;

    minor = digits_sum(1) + digits_sum(N-1);

    for(unsigned i = 2; i < N/2; i++)
    {
        unsigned test = digits_sum(i) + digits_sum(N-i);

        if(test < minor) minor = test;
    }

    cout << minor << endl;
    return 0;
}

unsigned digits_sum(unsigned n)
{
    unsigned place = 1;
    unsigned sum = 0;

    while (n)
    {
        unsigned place_value = n % (unsigned) 10;
        sum += place_value;
        n -= place_value;
        n /= 10;
    }
    
    return sum;
}