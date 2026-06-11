#include <bits/stdc++.h>
using namespace std;
void search(map<int, int> &a, int &max, int &index)
{
    for (auto i : a)
    {
        if (i.second > max)
        {
            index = i.first;
            max = i.second;
        }
    }
}
void search_sub(map<int, int> &a, int max, int index, int &sub_max, int &sub_index)
{
    for (auto i : a)
    {
        if (i.first != index && i.second > sub_max)
        {
            sub_index = i.first;
            sub_max = i.second;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int v[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    map<int, int> even{}, odd{};
    for (int i = 1; i <= n; i += 2)
        odd[v[i]]++;
    for (int i = 2; i <= n; i += 2)
        even[v[i]]++;
    int odd_max(0), even_max(0), odd_index(-1), even_index(-1), sub_odd_max(0), sub_even_max(0), sub_odd_index(-1), sub_even_index(-1);
    search(even, even_max, even_index);
    search(odd, odd_max, odd_index);
    int ans(0);
    if (even_index == odd_index)
    {
        search_sub(even, even_max, even_index, sub_even_max, sub_even_index);
        search_sub(odd, odd_max, odd_index, sub_odd_max, sub_odd_index);
        if (sub_odd_max == 0 && sub_even_max == 0)
            ans += even_max;
        else if (sub_odd_max > sub_even_max)
            odd_max = sub_odd_max;
        else
            even_max = sub_even_max;
    }
    ans += (n / 2 - even_max + (n - n / 2) - odd_max);
    cout << ans << endl;
}