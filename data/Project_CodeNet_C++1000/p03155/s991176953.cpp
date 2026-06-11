#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
using namespace std;

int main(void)
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << (a - b + 1) * (a - c + 1) << endl;
    return 0;
}