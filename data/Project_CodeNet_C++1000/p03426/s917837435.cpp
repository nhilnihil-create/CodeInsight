#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int,int>pii;
int main(){
    int H,W,D;
    map<int, pii> m;
    cin >> H >> W >> D;
    
    ll ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int tmp;
            cin >> tmp;
            tmp--;
            m[tmp] = make_pair(i,j);
        }
    }

    vector<int> v(H*W, 0);
    for(int i = 0; i < H*W; i++){
        if(i < D){
            v[i] = 0;
        } else { 
            v[i] = v[i-D] + abs(m[i].first - m[i-D].first) + abs(m[i].second - m[i-D].second);
        }
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int L,R;
        cin >> L >> R;
        L--; R--;
        cout <<  v[R] - v[L] << endl;
    }

}
