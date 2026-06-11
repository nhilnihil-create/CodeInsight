#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

int main()
{
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<char> t(Q), d(Q);
    for(int i=0; i<Q; i++) cin >> t[i] >> d[i];

    int l1 = -1, l2 = -1;
    int r1 = N, r2 = N;

    while(r1 - l1 > 1){
        int mid = (l1 + r1) / 2;
        int tmp = mid;
        bool isOK = false;
        for(int i=0; i<Q; i++){
            if(S[tmp] != t[i]) continue;
            if(d[i] == 'L') tmp--;
            else tmp++;
            if(tmp == -1) {isOK = true; break;}
            if(tmp == N) break;
        }
        if(isOK) l1 = mid;
        else r1 = mid;
    }

    while(r2 - l2 > 1){
        int mid = (l2 + r2) / 2;
        int tmp = mid;
        bool isOK = false;
        for(int i=0; i<Q; i++){
            if(S[tmp] != t[i]) continue;
            if(d[i] == 'L') tmp--;
            else tmp++;
            if(tmp == N) {isOK = true; break;}
            if(tmp == -1) break;
        }
        if(isOK) r2 = mid;
        else l2 = mid;
    }

    cout << l2 - r1 + 1 << endl;
    // printf("%d %d %d %d\n", l1, l2, r1, r2);
}