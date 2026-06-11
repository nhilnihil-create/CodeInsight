#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAX=1e5;
int main()
{
    string a;
    int n;
    cin >> n;
    int b = 0,c = 0,d = 0,sum = 0;
    while(n -- )
    {
        cin >> a;
        int l=a.length();
        if(a[0] == 'B')
            b ++ ;
        if(a[l - 1] == 'A')
            c ++ ;
        if(a[l - 1] == 'A' && a[0] == 'B')
            d ++ ;
        for(int i = 0 ; i < l ; i ++ )
        {
            if(a[i] == 'A' && a[i + 1] == 'B')
                sum ++ ;
        }
    }
    if(b == d && c == d && d != 0) //
        sum -- ;
    cout << sum + min(b,c);
    return 0;
}
