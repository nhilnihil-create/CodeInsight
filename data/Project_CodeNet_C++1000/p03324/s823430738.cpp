// atc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include    <algorithm>
using namespace std;


int main()
{
    int d, n;
    cin >> d >> n;

    int o = 1;

    for (int i = 0; i < d; i++) {
        o = o * 100;
    }

    int o2 = o * n;
    if (n == 100) o2 = o2 + o;
    printf("%d\n", o2);


    return 0;

}
