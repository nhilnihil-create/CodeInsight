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
    long long n, m, a, b, ans = 0;
    cin >> n >> m;
    vector<pair<long long, long long>> e;
    for(long long i = 0; i < n; ++i){
        cin >> a >> b;
        e.push_back(make_pair(a,b));
    }
    sort(e.begin(), e.end());
    long long i = 0, rest = m;
    while(rest > 0){
        if(rest >= e.at(i).second){
            ans += e.at(i).first * e.at(i).second;
            rest -= e.at(i).second;
        }
        else{
            ans += e.at(i).first * rest;
            break;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}