#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;

    string first_str = str.substr(0,2);
    string second_str = str.substr(2,2);

    stringstream first_str_temp(first_str);
    stringstream second_str_temp(second_str);

    int str1 = 0, str2 = 0;
    first_str_temp >> str1;
    second_str_temp >> str2;

    if (str1 <= 12 && str1>0 && str2 <= 12 && str2>0)
    {
        cout << "AMBIGUOUS" << endl;
    }
    else if(str1 <= 12 && str1>0)
    {
        cout << "MMYY" << endl;
    }
    else if(str2 <= 12 && str2>0)
    {
        cout << "YYMM" << endl;
    }
    else
    {
        cout << "NA" << endl;
    }
    return 0;
}
