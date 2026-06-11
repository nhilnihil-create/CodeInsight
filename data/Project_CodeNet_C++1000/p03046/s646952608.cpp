#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
typedef long long ll;
int main(){
    int m,k; cin >> m >> k;
    if(m == 0){
        if(k == 0) cout << 0 << " " << 0 << endl;
        else cout << "-1" << endl;
        return 0;
    }
    if(m == 1){
        if(k == 0) cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
        else cout << "-1" << endl;
        return 0;
    }
    if(k >= (1 << m)){
        cout << "-1" << endl;
        return 0;
    }
    deque<int> d;
    if(k != 0){
        d.push_back(0);
        d.push_back(k);
        FOR(i, 1, (1<<m)){
            if(i == k) continue;
            d.push_back(i);
            d.push_front(i);
        }
        d.push_front(0);
        d.push_back(k);
    }else{
        rep(i, (1<<m)){
            d.push_back(i);
            d.push_back(i);
        }
    }
    int s = d.size();
    rep(i, s) printf("%d%c", d[i], i == s-1 ? '\n' : ' ');
}