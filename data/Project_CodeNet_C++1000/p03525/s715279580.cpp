#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001


vector<int> M(13);
vector<int> T(24);

int solve(){
    if(M[0]>=1) return 0;
    if(M[12]>=2) return 0;
    
    vector<int> b;
    for(int i=0; i<13; i++){
        if(M[i]==1) b.push_back(i);
        if(M[i]==2){
            T[i]++;
            T[24-i]++;
        }
        if(M[i]>=3) return 0;
    }
    
    
    int len = (int)b.size();
    int mx = 0;
    T[0] = 1;
    for(int i=0; i<1<<len; i++){
        for(int j=0; j<len; j++){
            if((i>>j)&1){
                T[24-b[j]] = 0;
                T[b[j]] = 1;
            }else{
                T[b[j]] = 0;
                T[24-b[j]] = 1;
            }
        }
        
        vector<int> C = T;
        for(int &t:T) C.push_back(t);
        int mn = INF;
        int cnt = 0;
        for(int i=1; i<48; i++){
            cnt++;
            if(C[i]){
                mn = min(mn, cnt);
                cnt = 0;
            }
        }
        
        mx = max(mx, mn);
    }

    return mx;
}


int main() {
    int N; cin >> N;
    for(int i=0; i<N; i++){
        int d; cin >> d;
        M[d]++;
    }
    cout << solve() << endl;
    
    return 0;
}
