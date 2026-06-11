#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    if(n == 3) reverse(s.begin(), s.end());
    cout << s << endl;
}