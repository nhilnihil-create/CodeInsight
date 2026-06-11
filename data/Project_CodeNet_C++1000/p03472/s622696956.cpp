#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int n,h;
    cin >> n >> h;
    int mx = 1e9;
    multiset<P> s;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        s.insert(make_pair(a,mx));
        s.insert(make_pair(b,1));
    }
    int cnt = 0;
    while(h>0){
        P p = *(--s.end());
        s.erase(--s.end());
        if(p.second == 1){
            h -= p.first;
            cnt++;
        }else{
            cnt += (h/p.first);
            if(h%p.first) cnt++;
            h = 0;
        }
    }

    cout << cnt << endl;
    
}
