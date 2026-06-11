#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;

int main() {
    int K;
    cin >> K;
    vector<int> vec(K);
    for(int i = 0;i < K;i++) {
        cin >> vec.at(i);
    }
    reverse(vec.begin(),vec.end());
    ll Min = 2;
    ll Max = 2;
    bool ret = true;
    if(vec.at(0) != 2) {
        ret = false;
    }
    for(int i = 0;i < K;i++) {
        if(Max / vec.at(i) - (Min - 1) / vec.at(i) == 0) {
            ret = false;
            break;
        }
        else {
            Min = (Min + vec.at(i) - 1) / vec.at(i) * vec.at(i);
            Max = Max / vec.at(i) * vec.at(i) + vec.at(i) - 1;
        }
    }
    if(ret == false) {
        cout << -1 << endl;
    }
    else {
        cout << Min << " " << Max << endl;
    }
}