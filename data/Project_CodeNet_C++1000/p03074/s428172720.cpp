#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    for(auto &i : s)i -= '0';
    s.push_back(2);
    vector<pair<int,int>> ass;
    int cur = 1;

    for(int i = 1; i <= n; i++){
        if(s[i] == s[i - 1])cur++;
        else{
            ass.push_back({s[i - 1],cur});
            cur = 1;
        }
    }

    if(ass.front().first)ass.insert(ass.begin(), {0,0});
    if(!ass.back().first)ass.push_back({1,0});

    int sum = 0;
    cur = 0;
    int nax = 0;
    int past = 0;
    int m = ass.size();
    for(int i = 0; i < m; i++){
        sum += !ass[i].first;
        if(sum > k){
            while(sum > k){
                cur -= ass[past].second;
                sum -= !ass[past].first;
                past++;
            }
        }
        cur += ass[i].second;
        nax = max(cur, nax);
    }
    cout << nax << endl;

}