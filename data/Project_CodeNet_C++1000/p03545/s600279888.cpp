#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    
    int num[4];
    num[0] = s[0] - '0';
    num[1] = s[1] - '0';
    num[2] = s[2] - '0';
    num[3] = s[3] - '0';
    std::vector<int> ans(8);

    ans[0] = num[0] + num[1] + num[2] + num[3];
    ans[1] = num[0] - num[1] + num[2] + num[3];
    ans[2] = num[0] + num[1] - num[2] + num[3];
    ans[3] = num[0] + num[1] + num[2] - num[3];
    ans[4] = num[0] - num[1] - num[2] + num[3];
    ans[5] = num[0] + num[1] - num[2] - num[3];
    ans[6] = num[0] - num[1] + num[2] - num[3];
    ans[7] = num[0] - num[1] - num[2] - num[3];

    int index;
    for (int i = 0; i < 8; i++)
    {
        if(ans[i] == 7) {
            index = i;
        }
    }

    std::string anss = "";
    std::string a = std::to_string(num[0]);
    std::string b = std::to_string(num[1]);
    std::string c = std::to_string(num[2]);
    std::string d = std::to_string(num[3]);
    if (index == 0)
    {
        anss += a;
        anss += "+";
        anss += b;
        anss += "+";
        anss += c;
        anss += "+";
        anss += d;
    }
    else if (index == 1)
    {
        anss += a;
        anss += "-";
        anss += b;
        anss += "+";
        anss += c;
        anss += "+";
        anss += d;
    }
    else if (index == 2)
    {
        anss += a;
        anss += "+";
        anss += b;
        anss += "-";
        anss += c;
        anss += "+";
        anss += d;
    }
    else if (index == 3)
    {
        anss += a;
        anss += "+";
        anss += b;
        anss += "+";
        anss += c;
        anss += "-";
        anss += d;
    }
    else if (index == 4)
    {
        anss += a;
        anss += "-";
        anss += b;
        anss += "-";
        anss += c;
        anss += "+";
        anss += d;
    }
    else if (index == 5)
    {
        anss += a;
        anss += "+";
        anss += b;
        anss += "-";
        anss += c;
        anss += "-";
        anss += d;
    }
    else if (index == 6)
    {
        anss += a;
        anss += "-";
        anss += b;
        anss += "+";
        anss += c;
        anss += "-";
        anss += d;
    }
    else if(index == 7)
    {
        anss += a;
        anss += "-";
        anss += b;
        anss += "-";
        anss += c;
        anss += "-";
        anss += d;
    }

    anss += "=7";

    std::cout << anss << "\n";
}