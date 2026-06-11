#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = INT_MAX / 2;

int main() {
    int N; cin >> N;
    vector<int> v(N);
    pair<int, int> ma=make_pair(-INF, -1), mi=make_pair(INF,-1);
    for (int i = 0; i < N; i++)
    {    
        cin >> v[i];
        if(ma.first<v[i]){
            ma = make_pair(v[i], i);
        }
        if(mi.first>v[i]){
            mi = make_pair(v[i], i);
        }        
    }

    if(abs(ma.first)>=abs(mi.first)){
        cout << 2 * (N-1) << endl;
        for (int i = 0; i < N; i++)
        {
            if(i==ma.second) continue;
            cout << ma.second+1 << " " << i+1 << '\n';
        }
        for (int i = 1; i < N; i++)
        {
            cout << i << " " << i + 1 << '\n';
        }
    } else {
        cout << 2 * (N-1) << endl;
        for (int i = 0; i < N; i++)
        {
            if(i==mi.second) continue;
            cout << mi.second+1 << " " << i+1 << '\n';
        }
        for (int i = N; i > 1; i--)
        {
            cout << i << " " << i -1 << '\n';
        }
    }
}