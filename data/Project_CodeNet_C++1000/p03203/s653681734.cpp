#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int h, w, n;
vector <pair <int, int> > a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w >> n;
    a.resize(n);
    for(auto &i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end());
    int cnt = 0;
    for(auto &i : a){
        if(i.second + cnt < i.first) finish(i.first - 1);
        cnt += i.first - cnt == i.second;
    }
    cout << h << endl;
}
