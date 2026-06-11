#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <map>
#include <utility>
#include <list>
#include <climits>
#include <bitset>
#include <numeric>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i, n) for(auto i = (n).begin(); i != (n).end(); i++)
#define in_arr(type, a, n) copy_n(istream_iterator<type>(cin), n, (a).begin());
#define ll long long int

int m;

int which(int a, int b);

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    in_arr(int, a, n);
    m = accumulate(a.begin(), a.end(), 0, [](int a, int b){ return max(a, b); });
    int suit = accumulate(a.begin(), a.end(), 0, [](int a, int b){ return which(a, b); });
    cout << m << " " << suit << endl;
    return 0;
}

int which(int a, int b){
    int val_a = min(a, m - a);
    int val_b = min(b, m - b);
    return val_a < val_b ? b : a;
}
