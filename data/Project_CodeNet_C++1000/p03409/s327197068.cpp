#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

static const int INTINF = (2147483647);
static const ll LLINF = (9223372036854775807);
static const int MAX = 100001;
static const ll MOD = 1000000007;

namespace Printer{
    void print(vector<int> v){
        rep(i, v.size()){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    void print(vector<vector<int> > vv){
        rep(i, vv.size()){
            rep(j, vv[i].size()){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void print(pair<int, int> p){
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
};

//--global--//



//----------//

bool rused[101], bused[101];

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//

    int n;
    cin >> n;
    vector<pair<int, int> > red;
    vector<pair<int, int> > blue;
    rep(i, n){
        int a, b; cin >> a >> b;
        red.push_back(make_pair(b, a));
    }
    rep(i, n){
        int a, b; cin >> a >> b;
        blue.push_back(make_pair(a, b));
    }

    sort(ALL(blue));
    sort(ALL(red), greater<pair<int, int> >() );

    int cnt = 0;
    rep(i, blue.size()){
        if(bused[i] == true) continue;
        pair<int, int> nowB = blue[i];
        rep(j, red.size()){
            if(rused[j] == true) continue;
            pair<int, int> nowR = red[j];
            if(nowR.first < nowB.second && nowR.second < nowB.first){
                // Printer::print(nowB);
                // Printer::print(nowR);
                bused[i] = true;
                rused[j] = true;
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;
    
    return 0;
}
