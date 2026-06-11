#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

constexpr long long mod = 1000000007;
constexpr double eps = 0.00001;

int main() {
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> b(n);
    set<pair<int,int>> r;
    for(int i = 0;i < n;i++) {
        int s,t;
        scanf("%d %d",&s,&t);
        r.insert(make_pair(s,t));
    }
    for(int i = 0;i < n;i++) scanf("%d %d",&b[i].first,&b[i].second);
    sort(b.begin(),b.end());
    int c = 0;
    for(auto& e:b) {
        pair<int,int> p;
        bool u = false;
        for(auto f:r) {
            if(f.first < e.first && f.second < e.second) {
                u = true;
                p = f;
            }
        }
        if(!u) continue;
        for(auto f:r) if(f.first < e.first && f.second < e.second && p.second < f.second) p = f;
        r.erase(p);
        c++;
    }
    printf("%d",c);
}
