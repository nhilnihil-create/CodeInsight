#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,k;
    cin >> a>>b>>k;
    int ans =0;
    int x = 0;
    int i = min(a,b);
    while (x<k)
    {
        if(a%i ==0&&b%i ==0)
        {
            x++;
            if(x ==k)
            {
                ans +=i;
                break;
            }
        }
        i--;
    }
    cout << ans << endl;
}
