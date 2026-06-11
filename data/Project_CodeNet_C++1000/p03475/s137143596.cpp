#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int calc(int nowTime, int s, int f){
   if(nowTime <= s) return s - nowTime; 
   else {
       int div = (nowTime + f-1)/f;
       return (div*f - nowTime);
   }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> C(N-1), S(N-1), F(N-1);
    for(int i = 0; i < N-1; ++i) cin >> C[i] >> S[i] >> F[i];
    for(int j = 0; j < N; ++j){
        int nowTime = 0;
        for(int i = j; i < N-1; ++i){
            nowTime += calc(nowTime, S[i], F[i]);
            nowTime += C[i];
        }
        cout << nowTime << '\n';
    }
    return 0;
}