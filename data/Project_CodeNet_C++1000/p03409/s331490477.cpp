#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int n; cin >> n;
    vector<P> abx, cdx, aby, cdy;
    rep(i, n){
        int x, y;
        cin >> x >> y;
        abx.push_back(make_pair(x, y));
        aby.push_back(make_pair(y, x));
    }
    rep(i, n){
        int x, y;
        cin >> x >> y;
        cdx.push_back(make_pair(x, y));
        cdy.push_back(make_pair(y, x));
    }
   
    sort(aby.rbegin(), aby.rend());
    sort(cdx.begin(), cdx.end());

    int cnt = 0;
    vector<int> used(n+1, -1);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(used.at(j)!=-1) continue;
            if(aby.at(i).first<cdx.at(j).second && aby.at(i).second < cdx.at(j).first){
                cnt++; 
                used.at(j) = 1;
                break;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
