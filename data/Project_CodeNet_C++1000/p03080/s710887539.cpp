#include <iostream>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    string s;
    cin>>n>>s;
    if (count(s.cbegin(), s.cend(), 'R') > count(s.cbegin(), s.cend(), 'B'))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}
