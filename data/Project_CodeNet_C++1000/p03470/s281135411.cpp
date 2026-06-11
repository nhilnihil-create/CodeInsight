#include <bits/stdc++.h>
using namespace std;
using vi   = vector<int>;
using vvi  = vector<vi>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;
 

int main() {
    int N; cin >> N;
    set<int> d; 
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        d.insert(tmp);
    }
    
    int tmp_min=0, ans = 0;
    for (auto value : d) {
        if(value != tmp_min) ans++;

    }
    cout << ans;

}