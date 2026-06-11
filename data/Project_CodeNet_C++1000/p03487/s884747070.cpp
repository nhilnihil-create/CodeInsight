#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<int> a(N);
    unordered_map<int ,int> entry;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        entry[a[i]]++;
    }

    ll removal = 0;
    for(auto itr : entry){
        ll key = itr.first;
        ll value = itr.second;

        if(key == value) continue;
        if(key > value) removal += value;
        if(key < value) removal += value - key;
    }

    cout << removal << endl;

    return 0;
}
