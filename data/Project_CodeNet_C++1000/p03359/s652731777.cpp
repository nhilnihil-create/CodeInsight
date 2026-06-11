#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int a,b;
    cin >> a >> b;
    int cnt = 0;
    int x = 1, y = 1;
    while(x<=a)
    {

        if(x<a)
        cnt++;
        else if(x==a && x<=b)
        {
            cnt++;
        }

        x++;

    }
    cout << cnt << endl;
}
