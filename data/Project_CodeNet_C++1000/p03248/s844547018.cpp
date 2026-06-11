#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
string s;
int n;
int main()
{
    cin >> s;
    n = s.size();
    if (s[n - 1] != '0'){
        cout << -1;
        return 0;
    }
    for (int i = 0; n - i - 2 >= 0; i++)
    {
        if (s[i] != s[n - i - 2])
        {
            cout << -1;
            return 0;
        }
    }
    if (s[0] == '0')
    {
        cout << -1;
        return 0;
    }
    int counter = 2;
    int beta = n;
    cout << 1 << " " << 2 << "\n";
    for (int i = 1; beta > counter; i++)
    {
        if (s[i] == '0') {cout << counter << " " << beta << "\n"; beta--;}
        else {cout << counter << " " << counter + 1 << "\n"; counter++;}
    }
}