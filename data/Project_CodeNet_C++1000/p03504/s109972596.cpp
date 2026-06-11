#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N, C;
    cin >> N >> C;
    vector<int> vec(100005, 0), tmp(100005, 0);
    vector<vector<int>> data(N, vector<int> (3));
    int s,t,c;
    for (int i = 0; i < N; i++) {
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }
    for (int c = 1; c <= C; c++) {
        for (int i = 0; i < N; i++) {
            if(data[i][2] == c){
                tmp[data[i][0]]++;
                tmp[data[i][1]]--;
            }
        }
        for (int i = 0; i < 100005; i++) {
            if(tmp[i] == 1){
                vec[i-1]++;
            }
            else if(tmp[i] == -1){
                vec[i]--;
            }
        }
        for (int i = 0; i < 100005; i++) {
            tmp[i] = 0;
        }
    }

    int ans, tm;
    tm = 0; ans = 0;
    for (int i = 0; i < 100005; i++) {
        tm += vec[i];
        ans = max(ans, tm);
    }

    printf("%d\n", ans);


}
