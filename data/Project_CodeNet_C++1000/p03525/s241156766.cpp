#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int LMT = 23;
vector<int> pos;
int n,d[N];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&d[i]);
    }
    sort(d,d+n);
    int sta = 0;
    pos.push_back(0);
    for(int i=0;i<n;i++) {
        if(sta) pos.push_back((24-d[i])%24);
        else pos.push_back(d[i]);
        sta ^=1;
    }
    sort(pos.begin(),pos.end());
    int diff = 500;
    for(int i=0;i<pos.size()-1;i++) {
        diff = min(pos[i+1]-pos[i], diff);
    }
    diff = min(24-pos.back(), diff);
    printf("%d\n", diff);
    return 0;
}