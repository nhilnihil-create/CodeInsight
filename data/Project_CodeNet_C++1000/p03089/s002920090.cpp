#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;

int main(){
    int N; cin >> N;
    vector<int> B(N); for(int i = 0; i < N; i++) cin >> B[i];
    vector<int> V;
    for(int j = 0; j < N; j++){
        bool flag = true;
        for(int i = B.size()-1; i >= 0; i--){
            if(B[i] == i+1) {
                flag = false;
                V.push_back(B[i]);
                B.erase(B.begin()+i);
                break;
            }

        }
        if(flag){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = N-1; i >= 0; i--) cout << V[i] << endl;

}