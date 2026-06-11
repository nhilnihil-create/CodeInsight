#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int W, B;

signed main(){
    cin >> W >> B;
    W--; B--;
    cout << 100 << " " << 100 << endl;

    rep(i, 50){
        rep(j, 100){
            if(i%2==0 && j%2==0 && W > 0){
                W--;
                cout << ".";
            }
            else cout << "#";
        }
        cout << endl;
    }
    rep(i, 50){
        rep(j, 100){
            if(i%2==1 && j%2==0 && B > 0){
                B--;
                cout << "#";
            }
            else cout << ".";
        }
        cout << endl;
    }
}