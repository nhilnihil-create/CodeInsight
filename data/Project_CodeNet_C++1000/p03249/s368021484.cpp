#include <bits/stdc++.h>
using namespace std;

typedef pair<int64_t, int64_t> Pair;

void fail(){
    cout << -1 << endl;
    exit(0);
}

int main(){
    int i, j, k;
    int N;
    cin >> N;
    vector<Pair> D(N);

    for(i=0; i<N; i++){
        int64_t d;
        cin >> d;
        D.push_back({d, i});
    }
    sort(D.rbegin(), D.rend());

    map<int64_t, int64_t> mp;
    for(i=0; i<N; i++) mp[D[i].first] = i;

    vector<Pair> ans;
    vector<int64_t> dist_sub(N, 0);
    vector<int> num_sub(N, 1);

    for(i=0; i<N-1; i++){
        int64_t diff = N - 2*num_sub[i];
        int64_t pd = D[i].first - diff;
        if(mp.count(pd)){
            int p = mp[pd];
            ans.push_back({D[i].second+1, D[p].second+1});
            num_sub[p] += num_sub[i];
            dist_sub[p] += dist_sub[i] + num_sub[i];
        }else{
            fail();
        }
    }
    if(dist_sub[N-1] != D[N-1].first) fail();

    for(auto&& e : ans){
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}