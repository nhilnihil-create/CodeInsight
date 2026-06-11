#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    cin >> s;
 
    long int N = s.size();
 
    long int m1ve = 0;
    long int m2ve = 0;
 
    for(long int n=0; n<N; n++)
    {
        if(n % 2)
        {
            if(s[n] == '1')
            {
                m1ve++;
            }
 
            else
            {
                m2ve++;
            }
        }
 
        else
        {
            if(s[n] == '1')
            {
                m2ve++;
            }
 
            else
            {
                m1ve++;
            }
        }
    }
 
    cout << min(m1ve,m2ve);
    return 0;
}