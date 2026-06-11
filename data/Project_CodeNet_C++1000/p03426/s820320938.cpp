#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    int h,w,d;
    cin >> h >> w >> d;

    int tmp;

    vector<vector<pair<int,int>>> point(d, vector<pair<int,int>>(h * w / d + 1));

    rep(i, h){
        rep(j, w){
            cin >> tmp;

            point.at(tmp % d).at(tmp % d != 0 ? tmp / d : tmp / d - 1) = (mpair(i, j));
        }
    }

    cerr << "point comp" << endl;

    vector<vector<int>> magicsum(d, vector<int>(1, 0));

    rep(i, d){
        //cerr << point.at(i).size() << endl;
        for(int j = 1; j < point.at(i).size(); j++){
            int diffy = abs(point.at(i).at(j).first - point.at(i).at(j - 1).first);
            int diffx = abs(point.at(i).at(j).second - point.at(i).at(j - 1).second);

            magicsum.at(i).pback(magicsum.at(i).at(j - 1) + diffy + diffx);
        }
    }

    cerr << "magicsum comp" << endl;

    int q;
    cin >> q;

    rep(i, q){
        int l, r;
        cin >> l >> r;

        int m = l % d;
        l = l / d;
        r = r / d;

        if(m == 0){
            l--;
            r--;
        }

        //cerr << l << " " << r << endl;
        //cerr << magicsum.at(m).at(0) << " " << magicsum.at(m).at(1) << " " << magicsum.at(m).at(2) << " " << magicsum.at(m).at(3) << endl;

        cout << magicsum.at(m).at(r) - magicsum.at(m).at(l) << endl;
    }

    return 0;
}
