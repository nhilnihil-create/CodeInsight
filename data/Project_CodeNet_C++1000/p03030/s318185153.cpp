#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    pair<pair<string,int>,int> p[n];

    rep(i,n){
        string str;
        int point;
        cin >> str >>point;
        p[i]= make_pair(make_pair(str,-point),i+1);
    }

    std::sort(p,p+n);
    rep(i,n){
        cout << p[i].second <<endl;
    }
}