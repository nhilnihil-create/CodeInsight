#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    cin >> c;
    char ans;
    if (c == 'A')
    {
        ans = 'T';
    }else if (c == 'C')
    {
        ans = 'G';
    }else if (c == 'G')
    {
        ans = 'C';
    }else if (c == 'T')
    {
        ans = 'A';
    }
    
    cout << ans << endl;
    
    return 0;
}