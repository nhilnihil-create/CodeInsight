#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <map> 
#include <algorithm> 
using namespace std;
int main(void){
    long long n, m; cin >> n >> m;
    map<long long, long long> map;
    vector<long long> v(n);
    long long i = 0;
    long long ans = 0;
    while(i < n)  {
        long long tmp;
        cin >> tmp;
        if (map.count(tmp)) {
            map[tmp]++;
        } else {
            map[tmp] = 1;
            v.push_back(tmp);
        }
        i++;
    }
    i = 0;
    while(i < m)  {
        long long b,c;
        cin >> b >> c;
        if (map.count(c)) {
            map[c] += b;
        } else {
            map[c] = b;
            v.push_back(c);
        }
        i++;
    }
    sort(v.begin(), v.end(), greater<long long>());
    i = 0;
    while(i < v.size() && n > 0) {
        if (n > map[v[i]]) {
            ans += v[i] * map[v[i]];
            n -= map[v[i]];
        } else {
            ans += v[i] * n;
            n = 0;
        }
        i++;
    }
    cout << ans << endl;
}

