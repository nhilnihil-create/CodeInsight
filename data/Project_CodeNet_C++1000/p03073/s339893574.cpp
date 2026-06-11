#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    string s;
    cin >> s;

    int count_a=0;
    int count_b=0;
    for (int i=0;i<=s.length()-1;i++)
    {
        if ((i%2==0)&&(s[i]=='0'))
        {
            count_a++;
        }
        else if ((i%2==1)&&(s[i]=='1'))
        {
            count_a++;
        }
    }    

    for (int i=0;i<=s.length()-1;i++)
    {
        if ((i%2==0)&&(s[i]=='1'))
        {
            count_b++;
        }
        else if ((i%2==1)&&(s[i]=='0'))
        {
            count_b++;
        }
    }

    cout << s.length()-max(count_a,count_b) << endl;
    return 0;
}