#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, ll, ll> T;

int N;
bool p = false, m = false;
vector<int> a(51, 0);

void Incfunc(){ for(int i = 1; i < N; ++i) printf("%d %d\n", i, i + 1); }
void Decfunc(){ for(int i = N; i >= 2; --i) printf("%d %d\n", i, i - 1); }

int main(void){
    
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &a[i]);
        if(a[i] >= 0) p = true;
        else m = true;
    }
    
    if(p && !m){ printf("%d\n", N - 1); Incfunc(); }
    else if(!p && m){ printf("%d\n", N - 1); Decfunc(); }
    else{
        auto itr = max_element(a.begin() + 1, a.begin() + N + 1);
        int mx = *itr, idx = distance(a.begin(), itr);
        vector<P> v; 
        if(mx > 0){
            for(int i = 1; i <= N; ++i){
                if(a[i] >= 0) continue;
                int num = abs(a[i] - 0);
                int s = (num % mx) ? num / mx + 1 : num / mx;
                for(int j = 0; j < s && v.size() <= N; ++j) v.push_back(make_pair(idx, i));
            }
            if(v.size() <= N){
                printf("%d\n", (int)v.size() + N - 1);
                for(int i = 0; i < v.size(); ++i) printf("%d %d\n", v[i].first, v[i].second);
                Incfunc();
                return 0;
            }
        }
        
        itr = min_element(a.begin() + 1, a.begin() + N + 1);
        int mn = *itr; idx = distance(a.begin(), itr);
        vector<P> w;
        for(int i = 1; i <= N; ++i){
            if(a[i] < 0) continue;
            int num = abs(a[i] - -1);
            int s = (num % mn) ? num / mn + 1 : num / mn;
            for(int j = 0; j < s && w.size() <= N; ++j) w.push_back(make_pair(idx, i));
        }
        if(w.size() <= N){
            printf("%d\n", (int)w.size() + N - 1);
            for(int i = 0; i < w.size(); ++i) printf("%d %d\n", w[i].first, w[i].second);
            Decfunc();
            return 0;
        }
        
    }
    
    return 0;
}