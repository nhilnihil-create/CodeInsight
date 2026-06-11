#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s, t;
    cin >> s >> t;

    int arr1[26] = {0};
    int arr2[26] = {0};

    for (int i = 0; i < s.size(); i ++)
        arr1[s[i] - 'a'] ++;

    for (int i = 0; i < t.size(); i ++)
        arr2[t[i] - 'a'] ++;

    vector<int> v1, v2;

    for (int i = 0; i < 26; i ++) {
        if (arr1[i] > 0)
            v1.push_back(arr1[i]);
        if (arr2[i] > 0)
            v2.push_back(arr2[i]);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    bool flag = false;
    if (v1.size() == v2.size()) {
        for (int i = 0; i < v1.size(); i ++){
            if (v1[i] != v2[i]) {
                flag = true;
                break;
            }
        }
    } else {
        flag = true;
    }
    if (!flag)
        cout << "Yes";
    else
        cout << "No";


    return 0;
}