
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
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001

int N, Q;
string S;
string T;
string D;
map<char, int> M;


bool isOK(int m, char d){
    if(d=='R'){
        for(int i=0; i<Q; i++){
            if(T[i]==S[m]) m += M[D[i]];
            if(m < 0) return true;
        }
        return false;
    }
    
    for(int i=0; i<Q; i++){
        if(T[i]==S[m]) m += M[D[i]];
        if(m > N-1) return true;
    }
    return false;
}


int solveR(){
    int ok = -1;
    int ng = N;
    while(abs(ok-ng) > 1){
        int mid = (ok + ng) / 2;
        
        if(isOK(mid, 'R')) ok = mid;
        else ng = mid;
    }
    return ok;
}

int solveL(){
    int ok = N;
    int ng = -1;
    while(abs(ok-ng) > 1){
        int mid = (ok + ng) / 2;
        if(isOK(mid, 'L')) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main() {
    cin >> N >> Q;
    cin >> S;
    T.resize(Q);
    D.resize(Q);
    M['R'] = 1;
    M['L'] = -1;
    
    for(int i=0; i<Q; i++)
        cin >> T[i] >> D[i];
    
    int r_mx = solveR();
    int l_mn = solveL();
    
    cout << l_mn - r_mx - 1 << endl;
    return 0;
}
