#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> V;
    for(int i = 0; i < N; i++){
        int A, B;
        cin >> A  >> B;
        V.push_back(make_pair(A, B));
    }

    sort(V.begin(), V.end());

    int num = 0;
    long long ans = 0;
    for(auto v:V){
        for(int i = 0; i < v.second; ++i){
            ans += v.first ;
            num++;
            if(num == M){
                cout << ans << endl;
                return 0;
            }
        }
    }
    return 0;
}