#include<bits/stdc++.h>

#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    ll t = 0;
    bool B = false;
    ll rez = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'A')
        {
            if(B)
            {
                B = false;
                t = 1;
            }
            else t++;
        }
        else
        {
            if(s[i] == 'B')
            {
                if(B)
                {
                    t = 0;
                    B = false;
                }
                else B = true;
            }
            if(s[i] == 'C')
            {
                if(!B) t = 0;
                else
                {
                    rez += t;
                    B = false;
                }
            }
        }
    }
    cout << rez;

    return 0;
}
