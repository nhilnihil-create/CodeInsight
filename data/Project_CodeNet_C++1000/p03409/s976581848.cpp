#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N; cin >> N;
    vector<pair<int, int> > R, B;
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        R.push_back(make_pair(a, b));
    }
    for(int i = 0; i < N; i++){
        int c, d; cin >> c >> d;
        B.push_back(make_pair(c, d));
    }
    sort(R.begin(), R.end());
    sort(B.begin(), B.end());
    int cnt = 0;
    int RC[N]; for(int i = 0; i < N; i++) RC[i] = 0;
    int BC[N]; for(int i = 0; i < N; i++) BC[i] = 0;
    for(int i = 0; i < N; i++){
        pair<int, int> r, b;
        b = B[i];
        int y = -1, idx = -1;
        for(int j = 0; j < N; j++){
            r = R[j];
            //int y = -1, idx = -1;
            if(r.first < b.first && r.second < b.second){
                if(y < r.second) { 
                    if(RC[j] == 0){
                        y = r.second; 
                        idx = j;
                    }
                }
            }
        }
        if(idx != -1) {RC[idx] = 1; cnt++;}
    }
    cout << cnt << endl;
}