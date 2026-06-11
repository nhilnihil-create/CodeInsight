#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;
    string k = "keyence";
    string str1, str2;
    int find1, find2, find3;
    for (int i = 1; i <= 6; i++)
    {
        str1 = k.substr(0, i);
        str2 = k.substr(i, 7 - i);
        find1 = S.find(str1);
        find2 = S.rfind(str2);
        find3 = S.find(k);
        if ((find1 != string::npos && find2 != string::npos) && (find1 < find2) && (0 == find1) && (S.size() - (7 - i) == find2))
        {
            cout << "YES" << endl;
            return 0;
        }
        if (find3 != string::npos)
        {
            cout << "YES" << endl;
            return 0;
        }

    }

    cout << "NO" << endl;
    
    return 0;
}