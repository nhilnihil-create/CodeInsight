#include <iostream>
#include <string>
using namespace std;

int main()
{
     string s;
    cin >> s;
    int cnta = 0 , cntb = 0 , cntc = 0;
    int sz = s.size();
    for(int i = 0 ; i < sz ; i++)
    {
        if(s[i] == 'a')
        {
            cnta++;
        }
        if(s[i] == 'b')
        {
            cntb++;
        }
        if(s[i] == 'c')
        {
            cntc++;
        }
    }
    if(cnta > 0 && cntb > 0 && cntc > 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
