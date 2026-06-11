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
    int n, t, a, ans = -1;
    cin >> n >> t >> a;
    vector<int> h(n);
    for(int i = 0; i < n; ++i) cin >> h.at(i);
    double cand, anst = 5000.0;
    for(int i = 0; i < n; ++i){
        cand = t - h.at(i) * 0.006;
        if(abs(anst - a) > abs(cand - a)){
            anst = cand;
            ans = i;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}