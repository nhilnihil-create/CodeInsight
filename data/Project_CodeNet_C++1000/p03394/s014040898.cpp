#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    int N;
    cin >> N;

    if(N == 3){
        cout << "2 5 63\n"; return 0;
    }

    vector<int> ans(N);
    ans[0] = 2;
    ans[1] = 3;
    ans[2] = 4;
    ans[3] = 9;

    int num = 4;

    int next = 8;
    while(N - num >= 2 && next <= 29998){
        for(int i=0; i<2; i++) ans[num+i] = next + 2*i;
        num += 2;
        next += 6;
    }

    next = 15;
    while(N - num >= 2 && next <= 29994){
        for(int i=0; i<2; i++) ans[num+i] = next + 6*i;
        num += 2;
        next += 12;
    }

    next = 6;
    while(N - num >= 1 && next <= 30000){
        ans[num] = next;
        num++;
        next += 6;
    }

    // cout << num << endl;
    debug(ans);
}