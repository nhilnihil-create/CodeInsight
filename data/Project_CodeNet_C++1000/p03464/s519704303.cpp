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

    int k;
    cin >> k;

    vector<ll> a(k);

    rep(i, k){
        cin >> a[i];
    }

    pair<ll,ll> minmax = mpair(2, 2);

    for(int i = k - 1; i >= 0; i--){

        //cerr << minmax.first << " " << minmax.second << endl;

        if(a[i] > minmax.second){
            minmax.first = -1;
            break;
        }else{

            //min以上max以下の数字の内、a[i]で割り切れる最小値と最大値を求める
            ll tmpmin = minmax.first;
            ll tmp = minmax.first % a[i];

            if(tmp != 0){
                tmpmin = tmpmin + (a[i] - tmp);
            }

            //cerr << tmpmin << endl;

            if(tmpmin > minmax.second){
                minmax.first = -1;
                break;
            }

            tmp = minmax.second % a[i];
            ll tmpmax = minmax.second - tmp;

            //cerr << tmpmax << endl;

            if(tmpmax < minmax.first){
                minmax.first = -1;
                break;
            }

            minmax = mpair(tmpmin, tmpmax + a[i] - 1);

        }
    }

    if(minmax.first == -1){
        cout << -1 << endl;
    }else{
        cout << minmax.first << " " << minmax.second;
    }


}
