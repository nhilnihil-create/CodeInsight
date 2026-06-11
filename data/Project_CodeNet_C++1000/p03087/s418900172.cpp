#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int n, q, ans = 0;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> l(q), r(q), a(n);
    for(int i = 0; i < q; ++i) cin >> l.at(i) >> r.at(i);
    for(int i = 0; i < n - 1; ++i){
        if(i != 0) a.at(i + 1) = a.at(i);
        if(s.at(i) == 'A' && s.at(i + 1) == 'C') a.at(i + 1)++;
    }
    for(int i = 0; i < q; ++i){
        ans = a.at(r.at(i) - 1) - a.at(l.at(i) - 1);
        cout << ans << endl;
    }
    return 0;
}