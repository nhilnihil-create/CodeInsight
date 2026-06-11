#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> t(n), v(n);
    for(int i = 0; i < n; ++i){
        cin >> t.at(i);
    }
    for(int i = 0; i < n; ++i){
        cin >> v.at(i);
    }

    vector<ll> tstart(n, 0), tend(n, 0);
    for(int i = 0; i < n; ++i){
        if(i == 0){
            tend.at(0) = t.at(i);
        }else{
            tstart.at(i) = tend.at(i - 1);
            tend.at(i) = tstart.at(i) + t.at(i);
        }
    }

    const ll total_time = tend.back();
    vector<ll> speed(total_time + 1);
    for(ll i = total_time; i >= 0; --i){
        speed.at(i) = min(
            i,
            total_time - i
        );
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= total_time; ++j){
            if(tstart.at(i) <= j && j < tend.at(i)){
                speed.at(j) = min(speed.at(j), v.at(i));
            }else if(j < tstart.at(i)){
                speed.at(j) = min(
                    speed.at(j),
                    v.at(i) + (tstart.at(i) - j)
                );
            }else{
                speed.at(j) = min(
                    speed.at(j),
                    v.at(i) + (j - tend.at(i))
                );
            }
        }
    }

    vector<ll> is_flat(total_time, false);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < total_time; ++j){
            if(tstart.at(i) <= j && j < tend.at(i) &&
               speed.at(j) == v.at(i)){
                is_flat.at(j) = true;
            }
        }
    }

    double ans = 0;
    for(int i = 1; i <= total_time; ++i){
        // cerr << i << ' ' << speed.at(i - 1) << ' ' << speed.at(i) << ' ' << is_flat.at(i - 1) << endl;
        ans += (double)(speed.at(i - 1) + speed.at(i)) / 2.0;
        if(!is_flat.at(i - 1) && speed.at(i - 1) == speed.at(i)){
            ans += 0.25;
        }
    }
    printf("%.4f\n", ans);
    return 0;
}