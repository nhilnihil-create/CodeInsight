#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <string>


using namespace std;
int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }
int main()
{
    vector<int> intArray(3);

    for (int i = 0; i < 3; i++)
    {
        cin >> intArray[i];
    }

        
    sort(intArray.begin(),intArray.end());

    vector<string> strArray(3);

    for (int i = 0; i < 3; i++)
    {
        strArray[i] = std::to_string(intArray[i]);
    }

    string str2 = strArray[2] + strArray[1];
    int num1 = atoi(str2.c_str());

    int num2 = atoi(strArray[0].c_str());
        
    cout << num1+num2<< endl;

    return 0;


}

