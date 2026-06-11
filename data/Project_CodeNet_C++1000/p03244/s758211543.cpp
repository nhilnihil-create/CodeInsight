#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int n;
    cin >> n;
    vector<int> v1(n/2, 0), v2(n/2, 0);

    for (int i = 0; i < n; i++)
    {
        if(i%2 == 0){
            cin >> v1[i/2];
        } else {
            cin >> v2[(i-1)/2];
        }
    }

    map<int, int> count1, count2;

    for (int i = 0; i < n/2; i++)
    {
        count1[v1[i]]++;
    }
    for (int i = 0; i < n/2; i++)
    {
        count2[v2[i]]++;
    }

    
    int freq1_first = 0;
    int freq1_2nd = 0;
    int freq2_first = 0;
    int freq2_2nd = 0;

    int freq1_num, freq2_num;

    for (auto elem: count1)
    {
        if(freq1_first < elem.second) {
            freq1_2nd = freq1_first;
            freq1_first = elem.second;
            freq1_num = elem.first;
        } else if(freq1_2nd < elem.second){
            freq1_2nd = elem.second;
        }
    }

    for (auto elem: count2)
    {
        if(freq2_first < elem.second) {
            freq2_2nd = freq2_first;
            freq2_first = elem.second;
            freq2_num = elem.first;
        } else if(freq2_2nd < elem.second){
            freq2_2nd = elem.second;
        }
    }

    int ans;
    
    if(freq1_num != freq2_num){
        ans = (n/2 - freq1_first) + (n/2 - freq2_first);
    } else {
        int ans1 = (n/2 - freq1_first) + (n/2 - freq2_2nd);
        int ans2 = (n/2 - freq2_first) + (n/2 - freq1_2nd);

        ans = min(ans1, ans2);
    }

    cout << ans << endl;

    return 0;
}
