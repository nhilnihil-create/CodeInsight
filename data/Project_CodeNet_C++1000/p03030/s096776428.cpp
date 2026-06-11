#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
using tsii = tuple<string, int, int>;
using vtsii = vector<tsii>;

int main(void){
    int n;
    cin >> n;
    vtsii res(n);
    for(int i=0; i<n; i++){
        string s;
        int t;
        cin >> s >> t;
        res[i] = tsii(s, -t, i+1);
    }
    sort(res.begin(), res.end());
    for(tsii &t : res) cout << get<2>(t) << '\n';
    return 0;
}