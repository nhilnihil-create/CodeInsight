#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string N;
    cin >> N;

    int ans = 0;
    int l = (int)N.length();

    for (int i = l - 1; i >= 1; i--)
    {
        if (N[i] == '9')
        {
            ans += 9;
        }else
        {
            ans = (int)(N[0] - '0') - 1 + 9 * (l - 1);
            cout << ans << endl;
            return 0;
        }
        
    }
    
    ans += (int)(N[0] - '0');
    cout << ans << endl;

    return 0;
}