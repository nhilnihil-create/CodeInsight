#include <bits/stdc++.h>

using namespace std;

unsigned long long n;
string red , blue , a;
bool b[40];
map < pair < string , string > , unsigned long long > h1 , h2;

void bkt(unsigned long long k , unsigned long long n , unsigned long long st , map < pair < string , string > , unsigned long long > &c)
{
    if(k == n + 1)
    {
        red.clear();
        blue.clear();

        for(unsigned long long i = st ; i <= n ; i++)
            if(b[i] == 1)
                red += a[i];
            else blue += a[i];

        ++c[make_pair(red , blue)];
    }
    else
    {
        b[k] = 0;
        bkt(k + 1 , n , st , c);

        b[k] = 1;
        bkt(k + 1 , n , st , c);
    }
}

int main()
{
    unsigned long long ans = 0;

    cin >> n;
    cin >> a;

    bkt(0 , n - 1 , 0 , h1);
    bkt(n , 2 * n - 1 , n , h2);

    for(auto i = h1.begin() ; i != h1.end() ; i++)
    {
        red = i -> first.first;
        blue = i -> first.second;

        reverse(red.begin() , red.end());
        reverse(blue.begin() , blue.end());

        ans += h2[make_pair(blue , red)] * i -> second;
    }

    cout << ans;

    return 0;
}
