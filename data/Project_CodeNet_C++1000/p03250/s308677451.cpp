#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
using namespace std;


int main()
{
    vector<int> num(3);
    cin >>num[0] >> num[1] >> num[2];
    sort(num.begin(),num.end(),greater<int>());
    cout << 10*num[0] + num[1] + num[2] << endl;



}