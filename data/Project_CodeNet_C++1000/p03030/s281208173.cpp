#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n; cin >> n;
    char in[120];
    pair<pair<string, int>, int> p[110];
    rep(i, n){
        int t;
        cin >> in >> t;
        string tmp = in;
        p[i] = make_pair(make_pair(in, -t), i);
    }
    sort(p, p+n);
    rep(i, n)
        cout << p[i].second+1 << endl;
}