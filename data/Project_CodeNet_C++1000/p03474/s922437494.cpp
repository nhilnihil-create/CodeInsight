#include<iostream>
#include<string>
using namespace std;
int main ()
{
    int a, b, k = 0, t = 0;
    cin >> a >> b;
    string s;
    cin >> s;
    if(s[a] == '-')
    {
        s.erase (a,1);
        for(int i = 0; i < a + b; i++)
            {
                if(s[i] == '0' + 0 || s[i] == '0' + 1 || s[i] == '0' + 2 ||
                   s[i] == '0' + 3 || s[i] == '0' + 4 || s[i] == '0' + 5 ||
                   s[i] == '0' + 6 || s[i] == '0' + 7 || s[i] == '0' + 8 || s[i] == '0' + 9)
                k++;
                else
                t++;
            }
            if(t == 0)
                cout << "Yes";
                else cout << "No";
    }
    else
        cout << "No";
    return 0;
}