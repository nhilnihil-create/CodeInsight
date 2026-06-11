#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N, M;
    cin >> N >> M;

    int a[M], b[M];
    P l[M];
    for(int i=0; i<M; i++){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        l[i] = P(b[i], a[i]);
    }

    sort(l, l+M);

    int now = -1;
    int ans = 0;
    for(int i=0; i<M; i++){
        int s = l[i].second;
        int e = l[i].first;
        if((now < s) || (now>(e-1))) {
            now = e-1;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
