#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

// https://emtubasa.hateblo.jp/entry/2019/03/18/172356

int main() {
    int N, M;
    cin >> N;
    set<tuple<int,int,bool>> RB;
    rep(i, 2 * N) {
        int x, y;
        cin >> x >> y;
        RB.insert(make_tuple(x,y,i<N));
    }

/*
    for (auto x : R) {
        printf("%d,%d\n", x.first, x.second);
    }
    cout << endl;
    for (auto x : B) {
        printf("%d,%d\n", x.first, x.second);
    }
*/

   int res = 0;
   set<pair<int,int>> R;
   for (auto a : RB) { 
       if (get<2>(a)) {
           R.insert({get<1>(a),get<0>(a)}); // Push <y,x>
           continue;
       } else {
           for (auto r = R.rbegin(); r != R.rend(); r++) {
               if (get<1>(a) > r->first) {
                   //printf("HIT: (%d,%d)-(%d,%d)\n", get<0>(a), get<1>(a), r->second, r->first);
                   res++;
                   R.erase(*r);
                   break;
               }
           }
       }
   }
   cout << res << endl;
}
