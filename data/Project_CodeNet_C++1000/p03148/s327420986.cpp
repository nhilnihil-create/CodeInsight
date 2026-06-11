#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> P;
#define mod 1000000007
#define INF (1LL<<60)
 
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
#define YES puts("YES")
#define Yes puts("Yes")
#define NO  puts("NO")
#define No  puts("No")
#define ALL(v) (v).begin(), (v).end()
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
 
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
 
 
#if 1
//-------------
// DUMPマクロ
// https://www.creativ.xyz/dump-cpp-652/
 
// vector
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    for (T& x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream& operator<<(ostream& os, map<T, U>& map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream& operator<<(ostream& os, set<T>& set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
 
#define DUMPOUT cerr
 
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&& ... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}
#ifdef DEBUG
#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)
#endif


template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

#endif


void solve(){
    int N, K;
    cin >> N >> K;
    
    vector<P> td(N);
    rep(i,N) {
        cin >> td[i].first >> td[i].second;
    }
    sort(ALL(td),greater<>());
    vector<P> d;
    int last = -1;
    rep(i,N){
        if(td[i].first != last){
            d.push_back({td[i].second,+1});
            last = td[i].first;
        }else
            d.push_back({td[i].second,0});
    }
    sort(ALL(d), greater<>());
//    rep(i,N) dump(td[i]);
    rep(i,N) dump(d[i]);

    vector<int> v_used_1;
    priority_queue<int, vector<int>, greater<int> > pq_used_0;
    priority_queue<int> pq_notused_1;

    int total=0;
    int ans = 0;
    rep(i,N){
        if(i<K){
            if(d[i].second==1) v_used_1.push_back(d[i].first);
            else pq_used_0.push(d[i].first);
            total += d[i].first;
        }else{
            if(d[i].second==1) pq_notused_1.push(d[i].first);
        }
    }
    ans = max<int>(ans, total + v_used_1.size()*v_used_1.size() );
    
    //
    while(!pq_notused_1.empty()){
        if(pq_used_0.empty()) break;
        
        int t = pq_notused_1.top(); pq_notused_1.pop();
        v_used_1.push_back(t);

        int bottom = pq_used_0.top(); pq_used_0.pop();

        total = total - bottom + t;
        
        dump(v_used_1.size(), v_used_1);
        ans = max<int>(ans, total+v_used_1.size()*v_used_1.size() );
    }
    cout << ans << endl;
}

signed main(){
    cout << fixed << setprecision(18);
    cerr << fixed << setprecision(18);
    solve();
}
