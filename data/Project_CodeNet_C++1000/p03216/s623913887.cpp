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
    cin >> N;
    string S;
    cin >> S >> Q;
    vector<int> k(Q);
    for(int i=0; i<Q; i++) cin >> k[i];

    vector<ll> M(N);
    M[0] = (S[0]=='M') ? 1 : 0;
    for(int i=1; i<N; i++){
        M[i] = M[i-1];
        if(S[i]=='M') M[i]++;
    }

    for(int q=0; q<Q; q++){
        ll dp = 0;
        ll cd = (S[0]=='D') ? 1 : 0;
        ll sm = 0;
        for(int i=1; i<N; i++){
            if(i-k[q]>=0 && S[i-k[q]]=='D'){
                sm -= M[i-k[q]]; cd--;
            }
            if(S[i]=='D'){
                sm += M[i]; cd++;
            }
            if(S[i]=='C') dp += cd*M[i] - sm;
        }
        cout << dp << endl;
    }
}