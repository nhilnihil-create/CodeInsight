#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    long long mini = 10e15;
    cin >> n;
    vector<long long> vec(5);
    for(int i = 0; i < 5; ++i)
    {
        long long t;
        cin >> t;
        if(t < mini)
        {
            mini = t;
        }
    }

    long long ans = ceil(n/(double)mini);
    cout << ans + 4 << endl;
}