#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main(){

    int N, K;
    cin >> N >> K;
    set<int> in, out;
    pair<int, int> sushi[N];

    for(int i=0; i<N; i++){
        cin >> sushi[i].second >> sushi[i].first;
    }

    sort(sushi, sushi + N, greater<pair<int, int>>());
    
    long ans = 0;
    long x = 0;
    vector<int> minor, subs;

    for(int i=0; i<K; i++){
        ans += sushi[i].first;
        if (in.count(sushi[i].second) == 0) {
            in.insert(sushi[i].second);
            x++;
        }
        else {
            minor.push_back(sushi[i].first);
        }
    }

    long y = 0;

    for(int i=K; i<N; i++){
        if(out.count(sushi[i].second) == 0 && in.count(sushi[i].second) == 0){
            out.insert(sushi[i].second);
            y++;
            subs.push_back(sushi[i].first);
        }
    }

    ans += x * x;
    long cur = ans;
    int n_type = x + y;
    int cnt = 0;

    for(; x <= n_type && cnt < y && K - 1 - x >= 0; x++){
        cur += 2 * x + 1;
        cur -= minor[K - 1 - x] - subs[cnt];
        cnt++;
        ans = max(ans, cur);
    }

    cout << ans << endl;
    return 0;
}