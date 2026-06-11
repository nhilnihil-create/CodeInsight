#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=acos(-1);

bool comp(P p1, P p2){
    if (p1.first != p2.first) {
        return p1.first < p2.first;
    }
    else if (p1.second != p2.second) {
        return p1.second > p2.second;
    }
    else {
        return true;
    }
}

int main () {
    int N, M;
    cin >> N >> M;
    int P[M],Y[M];
    vector<vector<int>> a(N,vector<int>(0));
    rep(i,M) {
        cin >> P[i] >> Y[i];
        P[i]--;
        a[P[i]].push_back(Y[i]);
    }
    rep(i,N) {
        if(a[i].size()!=0) {
            sort(a[i].begin(),a[i].end());
        }
    }

    rep(i,M) {
        int idx = lower_bound(a[P[i]].begin(),a[P[i]].end(),Y[i])-a[P[i]].begin();
        idx++;
        int p = P[i];
        p++;
        printf("%06d",p);
        printf("%06d",idx);
        cout << endl;
    }
    
}
