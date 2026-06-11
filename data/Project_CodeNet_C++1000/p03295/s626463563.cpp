#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

bool compair(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}


int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > v;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), compair);

    int cur = -(1e9);
    int count = 0;
    for(int i = 0; i < m; i++){
        if(cur > v[i].first){
            continue;
        }
        cur = v[i].second;
        count++;
    }
    printf("%d\n", count);
    return 0;
}