#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    uint32_t D, N;

    cin >> D >> N;
    if(N!=100)
        cout << (uint32_t)(pow(100, D) * N) << endl;
    else
        cout << (uint32_t)(pow(100, D) * 101) << endl;

    return 0;
}