#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    string S;
    cin >> S;
    map<char,bool> mp;
    for(auto e:S){
        mp[e] = true;
    }
    if(mp['a']&&mp['b']&&mp['c']){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
