#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second

int main(){
    string s;
    cin >> s;
    vector<int> sub;
    int N = s.size();
    for(int i = 0; i <= N - 3; i++){
        sub.push_back(atoi(s.substr(i, 3).c_str()));
    }
    int min_dif = 999;
    for(int x : sub) min_dif = min(min_dif, abs(x-753));
    cout << min_dif << endl;
}
