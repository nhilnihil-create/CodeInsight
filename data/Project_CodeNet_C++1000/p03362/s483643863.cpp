#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    deque<int> integers;
    vector<int> prime;
    for (int i=2; i<55555; i++) integers.push_back(i);
    while (!integers.empty()) {
        deque<int> tmp;
        int p = integers[0];
        integers.pop_front();
        prime.push_back(p);
        for (auto i : integers){
            if (i % p != 0) tmp.push_back(i);
        }
        integers = tmp;
    }
    int n;
    vector<int> ans;
    cin >> n;
    for (auto p : prime){
        if (p % 5 == 1) ans.push_back(p);
        if (ans.size() == n) break;
    }
    for (auto x : ans) cout << x << " ";
    return 0;
}