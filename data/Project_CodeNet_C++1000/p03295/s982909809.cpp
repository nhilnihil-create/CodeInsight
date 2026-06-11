#include <bits/stdc++.h>
using namespace std;
//Islands War

typedef pair<int ,int> P;

int main(){
    int N, M;
    cin >> N >> M;
    vector<P> r(M);
    vector<bool> a(N - 1);

    for(int i = 0 ; i < M; ++i){
        cin >> r[i].second >> r[i].first;
    }

    a.assign(N - 1, false);

    sort(r.begin(), r.end()); // bについて昇順ソート

    int ans = 0;
    int b = -1;
    for(int i = 0; i < M; ++i){
        bool ok = false;
        // for(int j = r[i].second; j < r[i].first; ++j){
        //     if(a[j])ok = true;
        // }
        if(r[i].second <= b)ok = true;

        if(!ok){
            b = r[i].first - 1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}