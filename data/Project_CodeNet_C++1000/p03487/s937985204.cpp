#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n; cin >> n;
    ll answer = 0;
    vector<int> as(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> as.at(i);
    }

    map<int, int> mp;
    for(int i = 0; i < n; ++i)
    {
        mp[as.at(i)]++;
    }

    for(int i = 0; i < n; ++i)
    {
        if(mp[as.at(i)] < as.at(i))
        {
            answer += mp[as.at(i)];
            mp[as.at(i)] = 0;
        }
        else if(mp[as.at(i)] > as.at(i))
        {
            answer += mp[as.at(i)] - as.at(i);
            mp[as.at(i)] = as.at(i);
        }
    }

    cout << answer << endl;

    return 0;
}
