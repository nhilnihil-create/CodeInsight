#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, res1=0, res2=0, res3=0, res=0, res4=0, res5=0, sum = 0;
    cin >> n >> a >> b;
    for(int i=1; i<=n; i++)
    {
        res1 = i % 10;
        res2 = (i/10)%10;
        res3 = (i/100)%10;
        res4 = (i/1000)%10;
        res5 = (i/10000)%10;
        res = res1+res2+res3+res4+res5;
        if(((res >= a) && (res <= b))) sum += i;
    }
    cout << sum << endl;
    return 0;
}