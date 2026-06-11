#include <bits/stdc++.h>
 
#define REP(i,n) for(int i = 0; i < n; i++)
#define RREP(i, a, b) for (int i = a; i < (b); i++)
#define FOR(i, n) for (int i = n; i >= 0; i--)
using namespace std;
typedef long long ll;
 
void create_set(int k){
    int out[k+1][k];
 
    int cnt = 1;
 
    REP(i, k){
        REP(j, k){
            if (j >= i){
                out[i][j] = cnt;
                cnt++;
            }
 
        }
    }
 
    cnt = 1;
 
    REP(j, k){
        RREP(i, 1, k+1){
            if (i >= j+1){
                out[i][j] = cnt;
                cnt++;
            }
        }
    }
 
    REP(i, k+1){
        cout << k << " ";
        REP(j, k){
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main(){
    int N;
    cin >> N;
    int k = 1;
    bool good_number = false;
    while(k * (k+1) <= 2 * N){
        if (k * (k+1) == 2 * N) {
            good_number = true;
            break;
        }
        k++;
    }
    if(!good_number) {
        cout << "No" << endl;
        return 0;
    }
 
    cout << "Yes" << endl;
    cout << k+1 << endl;
    create_set(k);
 
    return 0;
}