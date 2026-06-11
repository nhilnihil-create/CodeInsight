#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
using lint = long long;
vector<tuple<long double, lint>> arr;
vector<unsigned long long> ans;
lint ten[16];
int K;
long double S(lint v) {
    int ret = 0;
    for(lint i = 1; v / i; i *= 10) {
        ret += (v / i) % 10;
    }
    return double(ret);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>K;
    ten[0] = 1;
    for(int i = 1; i < 16; i++) ten[i] = ten[i-1] * 10;
    for(int i = 1; i <= 15; i++) {
        for(int j = 1; j < min(ten[i], ten[4]); j++) {
            unsigned long long val = ten[i-1] - 1 + ten[i-1] * j;
            if(val <= 1e15) arr.emplace_back(val/S(val), val);
        }
    }
    sort(arr.begin(), arr.end());
    lint mv = 0;
    for(int i = 0; i < arr.size(); i++) {
        lint v, idx;tie(v, idx) = arr[i];
        if(idx > mv) {
            ans.push_back(idx);
            mv = idx;
        }
    }
    for(int i = 0; i < K; i++) {
        cout<<ans[i]<<'\n';
    }
    return 0;
}