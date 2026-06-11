#include <bits/stdc++.h>

using namespace std;
#define FOR(i,o,n) for(long long i = o;i<n;i++)
#define oneforall ios::sync_with_stdio(false);cin.tie(0);
#define all(v) (v).begin(),(v).end()
#define ini(...) int __VA_ARGS__; in(__VA_ARGS__)
#define inl(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define ins(...) string __VA_ARGS__; in(__VA_ARGS__)
#define int long long
const long long INF=1e18;
void in(){} template <typename T,class... U> void in(T &t,U &...u){ cin >> t; in(u...);}
void out(){cout << "\n";} template <typename T,class... U> void out(const T &t,const U &...u){ cout << t; if(sizeof...(u)) cout << " "; out(u...);}
typedef vector<int> vi;
typedef vector<long long> vl;
typedef long long ll;
typedef vector<pair<long, long > > vpll;
typedef vector<pair<int, int > > vpii;


int32_t main() {
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    oneforall
    
    ini(n);
    vi tmp;
    multiset<int> morty;
    int rick  = 0 ;
    FOR(i,0,31){
        int x = pow(2,i);
        tmp.push_back(x);
    }
    FOR(i,0,n){
        ini(x);
        morty.insert(x);
    }
    while(morty.size()!=0){
        int x1 = *morty.rbegin();
        morty.erase(prev(morty.end()));
        int tmp1 = *upper_bound(all(tmp),x1)-x1;
        if(morty.find(tmp1)!=morty.end()){
            rick++;
            morty.erase(morty.find(tmp1));
        }

    }
    out(rick);
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
