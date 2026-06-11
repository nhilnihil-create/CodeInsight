#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s,t;
    cin >> s >> t;
    vector<int> transS(26,-1);
    vector<int> transT(26,-1);

    bool result = true;
    for(int i = 0; i < (int)s.size(); ++i)
    {
        int a = s[i]-'a';
        int b = t[i]-'a';
        if((transS[a] != -1 || transT[b] != -1)
        && (transS[a] != b || transT[b] != a))
        {
            result = false;
            break;
        }
        transS[a] = b;
        transT[b] = a;
    }

    if(result)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}