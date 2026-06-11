#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int ans = 0;
    for(int i=1; i<=N; i+=2)
    {
        int yakusu = 0;
        for(int j=1; j*j <= i; j++)
        {
            if(j*j == i) yakusu++;
            else if(i%j==0) yakusu += 2;
        }
        if(yakusu==8) ans++;
    }
    cout << ans << endl;

    return 0;
}
