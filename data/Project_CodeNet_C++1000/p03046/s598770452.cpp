#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define all(x) (x).begin(),(x).end()

int main(){

    int M, K; cin >> M >> K;

    if (K == 0) {
        REP(i,1<<M) {
            cout << i << ' ' << i;
            if (i != (1<<M)-1) cout << ' '; 
        }
        cout << endl;
    }else if (M == 1 && K == 1) {
        cout << -1 << endl;
    }else if (K >= 1<<M) {
        cout << -1 << endl;
    }else if (K == 1){
        vector<int> v1;
        vector<int> v2 = {3,2,1,2,3};
        vector<int> v3;
        REP(i,1<<M) {
            if (i!=1 && i!=2 && i!=3) {
                v1.push_back(i);
                v3.push_back(i);
            }
        }
        reverse(all(v1));
        for (auto x:v1) cout << x << ' ';
        for (auto x:v2) cout << x << ' ';
        for (auto x:v3) cout << x << ' ';
        cout << 1 << endl;
    }else {
        vector<int> v1;
        vector<int> v2 = {K^1,1,K,1,K^1};
        vector<int> v3;
        REP(i,1<<M) {
            if (i!=1 && i!=K && i!=(K^1)) {
                v1.push_back(i);
                v3.push_back(i);
            }
        }
        reverse(all(v1));
        for (auto x:v1) cout << x << ' ';
        for (auto x:v2) cout << x << ' ';
        for (auto x:v3) cout << x << ' ';
        cout << K << endl;
    }
}