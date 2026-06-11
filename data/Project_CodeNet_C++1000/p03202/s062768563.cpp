#include <bits/stdc++.h>
using namespace std;

int N, A[200000];

bool check(int X){
    vector<pair<int, int>> V;
    V.emplace_back(0, 0);
    for(int i=1; i<N; i++) if(A[i-1] >= A[i]){
        while(V.back().first > A[i]) V.pop_back();
        if(V.back().first == A[i]){
            V.back().second++;
            while(V.back().second == X){
                int pt = V.back().first;
                V.pop_back();
                if(V.back().first == pt-1){
                    V.back().second++;
                }else{
                    V.emplace_back(pt-1, 1);
                }
            }
        }else{
            V.emplace_back(A[i], 1);
        }
        if(V[0].second > 0) return false;
    }
    return true;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    bool ok1 = true;
    for(int i=1; i<N; i++) if(A[i-1] >= A[i]) ok1 = false;
    if(ok1){
        cout << 1 << endl;
        return 0;
    }

    int ok = N, ng = 1;
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        (check(mid) ? ok : ng) = mid;
    }
    cout << ok << endl;
}
