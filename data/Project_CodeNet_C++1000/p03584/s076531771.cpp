#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void POSS(T condition){ if(condition) cout << "POSSIBLE" << endl; else cout << "IMPOSSIBLE" << endl; }
template<class T> inline void Poss(T condition){ if(condition) cout << "Possible" << endl; else cout << "Impossible" << endl; }
template<class T> inline void First(T condition){ if(condition) cout << "First" << endl; else cout << "Second" << endl; }
int character_count(string text, char character){ int ans = 0; for(int i = 0; i < text.size(); i++){ ans += (text[i] == character); } return ans; }
long power(long base, long exponent, long module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ long root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position move_pattern[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // double euclidean(position first, position second){ return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)); }
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++){ ans += to_string(*i) + " "; } ans.pop_back(); cout << ans << endl; }
template<class T> T gcd(T a, T b){ if(a && b){ return gcd(min(a, b), max(a, b) % min(a, b)); }else{ return a; }}
#define mod long(1e9 + 7)
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcountl(long(n))

struct item{
    int num;
    long value;
};

int main(){
    int N, K;
    cin >> N >> K;
    item items[N];
    long ans = 0;
    for(int i = 0; i < N; i++){
        cin >> items[i].num >> items[i].value;
        if((K | items[i].num) == K){
            ans += items[i].value;
        }
    }
    for(int i = 1; i < 30; i++){
        if((K >> i) & 1){
            int this_K = ((K & ~(1 << i)) | ((1 << i) - 1));
            long this_ans = 0;
            for(int j = 0; j < N; j++){
                if((this_K | items[j].num) == this_K){
                    this_ans += items[j].value;
                }
            }
            ans = max(ans, this_ans);
        }
    }
    cout << ans << endl;
}


