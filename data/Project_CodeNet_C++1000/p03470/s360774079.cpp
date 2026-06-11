#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), num(200);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    for(int i = 0; i < N; i++){
        num.at(A.at(i))++;
    }
    int ans = 0;
    for(int i = 0; i < 200; i++){
        if(num.at(i) > 0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}