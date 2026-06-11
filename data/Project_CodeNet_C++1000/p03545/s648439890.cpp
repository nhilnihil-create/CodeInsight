#include <bits/stdc++.h>
using namespace std;

string build_str(vector<int> nums, bitset<3> ops)
{
    string s = to_string(nums.at(0));
    for (int i = 0; i < 3; i++)
    {
        if (ops.test(i))
        {
            s += "+";
        }
        else
        {
            s += "-";
        }
        s += to_string(nums.at(i + 1));
    }

    s += "=7";
    return s;
}

int sum(vector<int> nums, bitset<3> ops)
{
    int sum = nums.at(0);
    for (int i = 0; i < 3; i++)
    {
        if (ops.test(i))
        {
            sum += nums.at(i + 1);
        }
        else
        {
            sum -= nums.at(i + 1);
        }
    }
    return sum;
}

int main()
{

    int N, A, B, C, D;
    cin >> N;

    D = N % 10;
    N /= 10;

    C = N % 10;
    N /= 10;

    B = N % 10;
    N /= 10;

    A = N % 10;

    vector<int> nums = {A, B, C, D};
    bitset<3> s;
    for (int tmp = 0; tmp < (1 << 3); tmp++)
    {
        s = bitset<3>(tmp);
        if (sum(nums, s) == 7)
        {
            break;
        }
    }

    cout << build_str(nums, s) << endl;
    return 0;
}