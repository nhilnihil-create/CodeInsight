/*
* welcome to my code!
* ------------------------------------------
* author : lynmisakura(twitter : @andoreiji11)
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define REP(i,n) for(int i = 0;i < n;i++)
#define all(x) x.begin(),x.end()
#define dup(x,y) (x + y - 1)/y
#define sz(v) (int)v.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template<class T> bool chmin(T& a,T b){if(a>b){a=b;return 1;}else return false;}
template<class T> bool chmax(T& a,T b){if(a<b){a=b;return 1;}else return false;}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int64_t m,k;cin >> m >> k;

    if(k >= (1LL << m)){
       cout << -1 << '\n';
       return 0;
    }

    if(m == 0){
        cout << "0 0" << '\n';
        return 0;
    }else if(m == 1){
        if(k == 1){
            cout << -1 << '\n';
        }else{
            cout << "0 0 1 1" << '\n';
        }
    }else{
        REP(i,(1LL << m))if(i != k)cout << i << ' ';
        cout << k << ' ';
        REP(i,(1LL << m))if((1LL << m) - 1 - i != k)cout << (1LL << m) - 1 - i << ' ';
        cout << k << '\n';
    }

}
