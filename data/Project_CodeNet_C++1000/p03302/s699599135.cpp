#include <iostream>
#include <math.h>
using namespace std;

int a,b;
char ans;
void solve()
{
    if(a*b==15)
    {
        ans = '*';
    }
    else if(a+b==15)
    {
        ans = '+';
    }
    else
    {
        ans = 'x';
    }

}
int main()
{
    cin >> a >> b;
    solve();
    cout << ans << endl;
    return 0;
}