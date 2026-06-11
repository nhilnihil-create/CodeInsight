#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pint;

vector<pint> A;
bool cmp(pint a, pint b) { return a.second < b.second; }

int main() {
    int N, M;
    cin >> N >> M;
    A.resize(M);
    for ( int i = 0; i < M; ++i){
        cin >> A[i].first >> A[i].second;
    }
    
    // 2つ目の昇順で並び替え
    sort(A.begin(),A.end(),cmp);
    int res = 0;
    int endtime = 0;
    for ( int i = 0; i < M; ++i){
        if ( A[i].first >= endtime ){
            endtime = A[i].second;
            ++res;
        }
    }
    
    cout << res << endl;
    
    return 0;
}