#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {
    vector<pair<int,int>>odd(100005);
    vector<pair<int,int>>even(100005);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int x; cin >> x;
        if(i%2 == 0){
            even[x].first++;
            even[x].second=x;
        }else {
            odd[x].first++;
            odd[x].second = x;
        }
    }
    sort(odd.begin(),odd.end());
    reverse(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    reverse(even.begin(),even.end());

    if(odd[0].second == even[0].second){
        if(odd[1].first + even[0].first > even[1].first+odd[0].first) cout << N-odd[1].first-even[0].first;
        else cout << N-even[1].first-odd[0].first;
    } else cout << N-odd[0].first-even[0].first;


    return 0;
}
