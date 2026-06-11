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
    cout << (uint32_t)(pow(100, D) * (N+N/100)) << endl;
    return 0;
}