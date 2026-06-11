#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int ina;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> ina;
        while (ina % 2 == 0)
        {
            ina /= 2;
            sum++;
        }
        
    }
    
    cout << sum << endl;

    return 0;
}