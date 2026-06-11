#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, ans = 0;
    string S;
    cin >> N >> S;
    for(int i = 1; i < N; ++i){
        unordered_map<char,int> X, Y;
        for(int j = 0; j < N; ++j){
            if(j < i) ++X[S[j]];
            else ++Y[S[j]];
        }
        int buf = 0;
        for(auto x: X){
            if(Y[x.first] != 0) ++buf; 
        }
        ans = max(ans, buf);
    }
    cout << ans << endl;
    return 0;
}