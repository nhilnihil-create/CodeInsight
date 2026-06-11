#include <iostream>
#include <string>
using namespace std;
int ans;
string a;
int main()
{
    cin >> a;
    if(a[0]=='1') ans++;
    if(a[1]=='1') ans++;
    if(a[2]=='1') ans++;
    cout << ans << endl;
}
