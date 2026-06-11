#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int main(){
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++) cin >> H[i];
    
    int count = 0;
    while(true){
        bool zero = true;
        bool all_zero = true;
        for(int &h : H){
            if(h > 0) {
                all_zero = false;
                if(zero){
                    count++;
                    zero = false;
                }
                h--;
            }else if(h == 0) {
                zero = true;
            }
        }
        if(all_zero) break;
    }
    cout << count << endl;
}