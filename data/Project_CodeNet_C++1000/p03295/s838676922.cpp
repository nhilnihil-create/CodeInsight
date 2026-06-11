#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, m; cin >> n >> m;
    vector<pii> vec(m);

    rep(i, m){
        cin >> vec.at(i).first >> vec.at(i).second;
        vec.at(i).first--;
        vec.at(i).second--;
    }
    sort(vec.begin(), vec.end(), [](const pii l_p, const pii r_p){
            return l_p.second != r_p.second ? l_p.second < r_p.second : l_p.first > r_p.first;
        });
    int brige = vec.at(0).second-1;
    int count=1;
    for(int i = 1; i < m; i++){
        if(vec.at(i).first <= brige && brige < vec.at(i).second) continue;
        brige = vec.at(i).second-1;
        count++;
    }
    cout << count << endl;
    return 0;
}
