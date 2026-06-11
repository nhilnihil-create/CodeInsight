#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<cmath>
#include<limits>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
using namespace std;

ll calc_profit(vvi Profit,vi count){
    ll ans = 0;
    for(int i = 0; i < Profit.size(); i++){
        ans += Profit[i][count[i]];
    }

    return ans;
}

int main(){
    int N; cin >> N;
    vector<vector<int>> Stores(N,vi(10));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10; j++){
            cin >> Stores[i][j];
        }
    }
    vvi Profit(N,vi(11));
    rep(i,N) rep(j,11) cin >> Profit[i][j];

    ll max = -int_INF;
    for(int k = 1; k < (1 << 10); k++){
        bitset<10> bs(k);
        vi Count(N);

        for(int p = 0; p < 10; p++){
            if(bs[p] == true){
                for(int q = 0; q < N; q++){
                    if(Stores[q][p] == true){
                        Count[q]++;
                    }
                }
            }
        }

        int prof = calc_profit(Profit,Count);
        max < prof ? max = prof:1;
    }

    cout << max << endl;
    sysp;
}