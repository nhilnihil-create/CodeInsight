#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int N;
    cin >> N;
    long long int num = 0;
    vector<long long int> v;
    vector<long long int> v_all;
    vector<long long int> v_ans;
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    for (int i = 1; i < 10; i++)
    {
        vector<long long int> v_tmp;
        for (auto vv : v)
        {
            v_tmp.push_back(3 * pow(10, i) + vv);
            v_tmp.push_back(5 * pow(10, i) + vv);
            v_tmp.push_back(7 * pow(10, i) + vv);
        }
        v = v_tmp;
        for (auto vv : v)
        {
            v_all.push_back(vv);
        }

        std::sort(v_all.begin(), v_all.end());
    }
    // for (auto vv : v_all)
    for (auto it = v_all.begin(); it != v_all.end(); ++it)
    {
        // cout << *it << endl;
        // cout << vv << endl;
        string s = to_string(*it);
        // cout << s << endl;
        int c7 = 0, c5 = 0, c3 = 0;
        c3 = count(s.begin(), s.end(), '3');
        c5 = count(s.begin(), s.end(), '5');
        c7 = count(s.begin(), s.end(), '7');
        if (c3 > 0 && c5 > 0 && c7 > 0 && (int)(*it / 100) >= 1)
        {
            ;
        }
        else
        {
            // cout << c3 << ", " << c5 << ", " << c7 << endl;
            v_all.erase(std::remove(v_all.begin(), v_all.end(), *it), v_all.end());
            it--;
        }

        // if (*it == 3577)
        //     break;
    }
    for (auto vv : v_all)
    {
        if (vv <= N)
        {
            num++;
            // cout << vv << endl;
        }
    }
    cout << num << endl;
    return 0;
}
