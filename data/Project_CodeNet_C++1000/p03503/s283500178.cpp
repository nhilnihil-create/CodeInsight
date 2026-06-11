/**
*    author:  souzai32
*    created: 14.08.2020 17:46:20
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
typedef long long ll;
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<vector<int>> f(n,vector<int>(10));
    rep(i,n){
        rep(j,10) cin >> f.at(i).at(j);
    }
    vector<vector<int>> p(n,vector<int>(11));
    rep(i,n){
        rep(j,11) cin >> p.at(i).at(j);
    }

    ll benefit,ans=ll(-1e9),count;
    vector<int> open(10,0);

    for(int i=1; i<1024; i++){
        open.at(0)++;
        for(int j=0; j<9; j++){
            if(open.at(j)==2){
                open.at(j)=0;
                open.at(j+1)++;
            }
        }
        benefit=0;
        for(int j=0; j<n; j++){
            count=0;
            for(int k=0; k<10; k++){
                if(f.at(j).at(k) && open.at(k)) count++;
            }
            benefit+=p.at(j).at(count);
        }
        ans=max(ans,benefit);
    }
    cout << ans << endl;

    return 0;
}