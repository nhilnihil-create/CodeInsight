#include<iostream>
using namespace std;
int main(void)
{
    string s;
    cin >> s;
    for(int i=0;i<3;i++)
        cout << (char)(106-(int)s[i]);
    return 0;
}
