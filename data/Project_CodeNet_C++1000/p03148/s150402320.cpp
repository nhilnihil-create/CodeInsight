#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define itrdebug(x) cerr << #x << " "; for (auto & el : (x)) {cerr << (el) << " ";} cerr << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define debug(x)
#define itrdebug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;

void solve(long long N, long long K, std::vector<long long> t, std::vector<long long> d){
    multiset<pair<int, int>> all, notIncluded, included;
    unordered_map<int, int> cnt;
    rep(i,0,N) all.insert({-d[i], t[i]});
    notIncluded = all;
    ll answer = 0;
    for (const auto& p : all) {
        if (included.size() == K) break;
        if (cnt.find(p.second) == cnt.end()) {
            cnt[p.second]++;
            answer += abs(p.first);
            notIncluded.erase(notIncluded.find(p));
            included.insert({abs(p.first), p.second});
        }
    }
    vector<pair<int, int>> toBeRemoved;
    for (const auto& p : notIncluded) {
        if (included.size() == K) break;
        cnt[p.second]++;
        answer += abs(p.first);
        toBeRemoved.push_back(p);
        included.insert({abs(p.first), p.second});
    }
    for (const auto& p : toBeRemoved) notIncluded.erase(notIncluded.find(p));
    for (const auto& p : included) {
        auto add = notIncluded.begin();
        auto remove = included.find(p);
        if (add == notIncluded.end() || remove == included.end() || abs(add->first) <= abs(remove->first)) break;
        if (add->second == remove->second || pow(cnt.size()-1,2) + abs(add->first) > pow(cnt.size(), 2) + abs(remove->first)) {
            notIncluded.erase(add);
            answer += abs(add->first) - abs(remove->first);
            cnt[remove->second]--;
            cnt[add->second]++;
            if (cnt[remove->second] == 0) cnt.erase(remove->second);
        }
    }
    answer += pow(cnt.size(),2);
    cout << answer << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> t(N);
    std::vector<long long> d(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&t[i]);
        scanf("%lld",&d[i]);
    }
    solve(N, K, std::move(t), std::move(d));
    return 0;
}
