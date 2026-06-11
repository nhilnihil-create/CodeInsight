#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;

int main(){
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;

    vector<long> A(X), B(Y), C(Z);
    for(int i=0; i<X; i++){
        cin >> A[i];
    }
    for(int i=0; i<Y; i++){
        cin >> B[i];
    }
    for(int i=0; i<Z; i++){
        cin >> C[i];
    }
    sort(A.begin(), A.end(), greater<long>());
    sort(B.begin(), B.end(), greater<long>());
    sort(C.begin(), C.end(), greater<long>());

    priority_queue<pair<long, tuple<int, int, int>>> q;
    q.push(make_pair(A[0]+B[0]+C[0], make_tuple(0,0,0)));
    map<tuple<int, int, int>, bool> used;
    used[make_tuple(0,0,0)] = true;
    int cnt = 0;
    vector<long> ans;
    while(!q.empty() && cnt<K){
        long num = q.top().first;
        ans.push_back(num);
        cnt++;
        int ai = get<0>(q.top().second);
        int bi = get<1>(q.top().second);
        int ci = get<2>(q.top().second);
        q.pop();

        if(ai+1<X && !used[make_tuple(ai+1,bi,ci)]){
            q.push(make_pair(num-A[ai]+A[ai+1], make_tuple(ai+1, bi, ci)));
            used[make_tuple(ai+1,bi,ci)] = true;
        }
        if(bi+1<Y && !used[make_tuple(ai,bi+1,ci)]){
            q.push(make_pair(num-B[bi]+B[bi+1], make_tuple(ai, bi+1, ci)));
            used[make_tuple(ai,bi+1,ci)] = true;
        }
        if(ci+1<Z && !used[make_tuple(ai,bi,ci+1)]){
            q.push(make_pair(num-C[ci]+C[ci+1], make_tuple(ai, bi, ci+1)));
            used[make_tuple(ai,bi,ci+1)] = true;
        }
    }

    for(int i=0; i<cnt; i++){
        cout << ans[i] << endl;
    }

    return 0;
}
