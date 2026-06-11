#include <bits/stdc++.h>
using namespace std;

int main(){
    pair<pair<string, int>, int> p[120];
    int n, a;
    string s;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        cin >> s >> a;
        p[i] = make_pair(make_pair(s, -a), i);
    }
    sort(p, p+n);
    for(int i=0; i<n; i++) printf("%d\n", p[i].second+1);
}