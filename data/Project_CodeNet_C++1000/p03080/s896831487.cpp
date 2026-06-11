#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;


int main()
{
    int N;
    cin >> N;

    string s;
    cin >> s;

    int r = 0;
    char R = 'R';
    for (int i = 0; i < s.size(); i++)
    {
        if ( s[i] == R) r++;
    }


    string result = "No";

    if (r > s.size() - r)
    {
        result = "Yes";
    }
    
    cout << result;

    return 0;
}
