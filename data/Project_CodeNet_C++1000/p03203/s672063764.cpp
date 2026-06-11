#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

bool comp(i_i a, i_i b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    //cout.precision(10);
    int h, w, n;
    cin >> h >> w >> n;
    vector<i_i> v;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < v.size(); i++){
        //cout << v[i].first << " " << v[i].second << endl;
    }
    int back = 0;
    for(int i = 0; i < v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        if(x > (y + back)){
            cout << x - 1 << endl;
            return 0;
        }
        if(x == (y + back)) back++;
    }
    cout << h << endl;
    return 0;
}
