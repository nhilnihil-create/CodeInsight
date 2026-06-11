#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main( ) {
    // freopen("C.01.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, res=0;
    vi vodd, veven;
    rep(i,0,3){
        cin >> t;
        (t&1)?vodd.push_back(t):veven.push_back(t);      
    }
    if (sz(vodd)==3){
        sort(all(vodd));
        res = (2*vodd[2]-vodd[1]-vodd[0])>>1;
    }
    else if (sz(vodd)==2){
        if (veven[0]>= max(vodd[0],vodd[1])){
            res = ((2*veven[0]-(vodd[0]+vodd[1]+2))>>1) + 1;
        }
        else{
            res = (abs(vodd[0]-vodd[1])>>1) + ((max(vodd[0],vodd[1])+1-veven[0])>>1) + 1;
        }
    }
    else if (sz(vodd)==1){
        if (vodd[0] >= max(veven[0], veven[1])){
            res = ((2*vodd[0]- (veven[0]+veven[1]+2))>>1) +1;
        }
        else{
            res = (abs(veven[0]-veven[1])>>1) + ((max(veven[0],veven[1])+1 - vodd[0])>>1) + 1;
        }
    }
    else{
        sort(all(veven));
        res = (2*veven[2]-veven[1]-veven[0])>>1;
    }
    // check odd, even situation
    cout << res <<endl;
    return 0;
}