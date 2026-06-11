#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int64_t> X(N), Y(N);
    for(int i=0; i<N; i++) cin >> X[i] >> Y[i];
    for(int i=0; i<N; i++) if((X[i] + Y[i] + X[0] + Y[0]) % 2){
        cout << -1 << endl;
        return 0;
    }

    vector<int64_t> D;
    for(int d=31; d>=0; d--) D.push_back(1LL<<d);
    if((X[0] + Y[0]) % 2 == 0) D.push_back(1);

    cout << D.size() << endl;
    for(int64_t d : D) cout << d << " ";
    cout << endl;

    for(int i=0; i<N; i++){
        int64_t x = X[i] + Y[i];
        int64_t y = X[i] - Y[i];
        string ans;
        for(int64_t d : D){
            if(x >= 0 && y >= 0){
                x -= d;
                y -= d;
                ans.push_back('R');
            }else if(x >= 0){
                x -= d;
                y += d;
                ans.push_back('U');
            }else if(y >= 0){
                x += d;
                y -= d;
                ans.push_back('D');
            }else{
                x += d;
                y += d;
                ans.push_back('L');
            }
        }
        cout << ans << endl;
    }
}