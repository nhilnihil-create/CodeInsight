#include <iostream>
using namespace std;
int main()
{
  
    int n = 700; string s; cin >> s;
    for (int i = 0; i < 3; ++i)
    {
        if (s[i] == 'o')
            n += 100;
    }
    cout << n << endl;


    return 0;
}
