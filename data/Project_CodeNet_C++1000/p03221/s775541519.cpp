#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> t;
    rep(i, M){
        int p, y;
        cin >> p >> y;
        t.emplace_back(p, y, i);
    }
    sort(t.begin(), t.end());

    vector<int> fr(M);
    vector<int> ba(M);
    for(int i = 0; i < M; ){
        int prefecture = get<0>(t[i]);
        int j = 0;
        while(prefecture == get<0>(t[i]) && i < M){
            int index = get<2>(t[i]);
            fr[index] = prefecture;
            ba[index] = j+1;
            j++;
            i++;
        }
    }
    rep(i, M){
        printf("%06d", fr[i]);
        printf("%06d\n", ba[i]);
    }
    return 0;
}