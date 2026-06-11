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
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
using namespace std;
#define int ll
bool bysecond(const vi& lhs, const vi& rhs) {
    if (lhs[1] != rhs[1]) {
        return lhs[1] > rhs[1];
    }
    else {
        return lhs[0] > rhs[0];
    }
   
}

bool byfirst(const vi& lhs, const vi& rhs) {
    if (lhs[0] != rhs[0]) {
        return lhs[0] > rhs[0];
    }
    else {
        return lhs[1] > rhs[1];
    }
}

signed main() {
    int N, H; cin >> N >> H;
    vector<vector<int>> vec(N, vi(2));
    rep(i, N) {
        cin >> vec[i][0] >> vec[i][1];
    }

    sort(ALL(vec),byfirst);
    vi maxA = vec[0];
    vec.erase(vec.begin());
    sort(ALL(vec), bysecond);

    int index_for_vec = 0;
    int turn = 0;
    int curr = 0;
    if (vec.size() != 0) {
        while (H - curr > maxA[1]) {
            if (index_for_vec != vec.size()) {
                if (vec[index_for_vec][1] > maxA[0]) {
                    curr += vec[index_for_vec][1];
                    index_for_vec++;
                    turn++;
                }
                else {
                    turn += (H - curr - maxA[1]) / maxA[0];
                    curr += maxA[0] * ((H - curr - maxA[1]) / maxA[0]);
                    if ((H - curr - maxA[1]) % maxA[0] != 0) {
                        turn++;
                        curr += maxA[0];
                    }

                    break;
                }
            }
            else {
                turn += (H - curr - maxA[1]) / maxA[0];
                curr += maxA[0] * ((H - curr - maxA[1]) / maxA[0]);
                if ((H - curr - maxA[1]) % maxA[0] != 0) {
                    turn++;
                    curr += maxA[0];
                }

                break;
            }
        }
        if (curr < H) {
            turn++;
        }
    }
    else {
        //maxAのみ使用する
        turn++;
        H -= maxA[1];
        turn += H / maxA[0];
        if (H % maxA[0] != 0) turn++;
    }
   
    cout << turn << endl;

}