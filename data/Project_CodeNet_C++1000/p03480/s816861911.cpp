#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    list<int> l(1, 1);
    for (size_t i = 0; i + 1 < s.size(); i++)
    {
        if (s[i] == s[i + 1])
        {
            l.back()++;
        }
        else
        {
            l.push_back(1);
        }
    }
    while (l.size()>2)
    {
        if (l.front()<l.back())
        {
            *next(l.begin())+=l.front();
            l.pop_front();
        }
        else
        {
            *next(l.rbegin())+=l.back();
            l.pop_back();
        }
    }
    cout << max(l.front(), l.back()) << endl;

    return 0;
}
