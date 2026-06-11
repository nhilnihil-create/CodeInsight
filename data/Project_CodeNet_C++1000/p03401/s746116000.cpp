#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    int ans = max(vec[0], -1 * vec[0]);
    rep(i,N - 1){
        ans += max(vec[i + 1] - vec[i], vec[i] - vec[i + 1]);
    }
    ans += max(vec[N - 1], -1 * vec[N - 1]);
    int ans_copy = ans;
    ans_copy += (max(vec[1], -1 * vec[1]) - max(vec[0], -1 * vec[0]) - max(vec[1] - vec[0], vec[0] - vec[1]));
    cout << ans_copy << endl;
    rep(i,N - 2){
        ans_copy = ans;
        ans_copy += (max(vec[i + 2] - vec[i], vec[i] - vec[i + 2]) - max(vec[i + 2] - vec[i + 1], vec[i + 1] - vec[i + 2]) - max(vec[i + 1] - vec[i], vec[i] - vec[i + 1]));
        cout << ans_copy << endl;
    }
    ans_copy = ans;
    ans_copy += max(vec[N - 2], -1 * vec[N - 2]) - max(vec[N - 1], -1 * vec[N - 1]) - max(vec[N - 2] - vec[N - 1], vec[N - 1] - vec[N - 2]);
    cout << ans_copy << endl;
}
