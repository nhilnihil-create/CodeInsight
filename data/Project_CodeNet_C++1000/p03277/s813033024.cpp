#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

class BinaryIndexedTree
{
private:
    int n;
    vector<int> data;
public:
    BinaryIndexedTree(int n){ // コンストラクタ
        this->n = n;
        data.assign(n+1, 0);
    }
    void add(int k, int x){ // k番目の要素にxを加算する
        ++ k;
        while(k <= n){
            data[k] += x;
            k += k & -k;
        }
    }
    int sum(int k){ // 区間[0,k]の総和を返す
        ++ k;
        int ret = 0;
        while(k > 0){
            ret += data[k];
            k -= k & -k;
        }
        return ret;
    }
    int sum(int a, int b){ // 区間[a,b]の総和を返す
        return sum(b) - sum(a-1);
    }
};

long long inversionNumber(const vector<int>& v)
{
    int n = v.size();
    vector<pair<int, int> > p(n);
    for(int i=0; i<n; ++i)
        p[i] = make_pair(v[i], i);
    sort(p.rbegin(), p.rend());

    BinaryIndexedTree bit(n);
    long long ans = 0;
    for(int i=0; i<n; ++i){
        ans += bit.sum(p[i].second);
        bit.add(p[i].second, 1);
    }
    return ans;
}

int solve(const vector<int>& a)
{
    int n = a.size();
    int left = *min_element(a.begin(), a.end());
    int right = *max_element(a.begin(), a.end()) + 1;
    while(right - left > 1){
        int mid = (left + right) / 2;
        vector<int> b(n+1, 0);
        for(int i=0; i<n; ++i){
            b[i+1] = b[i];
            if(mid <= a[i])
                ++ b[i+1];
            else
                -- b[i+1];
        }

        if(inversionNumber(b) > n * (n + 1LL) / 4)
            right = mid;
        else
            left = mid;
    }
    return left;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];
    cout << solve(a) << endl;

    return 0;
}
