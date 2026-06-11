#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int n;
vector<int> bmb;
int a, b, c;
int ans;
void dfs(vector<int> &A){
    if(A.size() == n){
        // 得られている数列は、全探索したいものの1つを表している
        int len_a = 0, len_b = 0, len_c = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == 0){
                len_a += bmb[i];
                cnt++;
            }
            else if(A[i] == 1){
                len_b += bmb[i];
                cnt++;
            }
            else if(A[i] == 2){
                len_c += bmb[i];
                cnt++;
            }
        }

        int tmp_ans = 0;
        if(len_a > 0 && len_b > 0 && len_c > 0){
            tmp_ans += 10 * (cnt - 3);
            tmp_ans += abs(a - len_a) + abs(b - len_b) + abs(c - len_c);
            ans = min(tmp_ans, ans);
        }
        return;
    }

    for(int v = 0; v < 4; v++){
        A.push_back(v);
        dfs(A);
        A.pop_back();
    }
}



int main(void){
    cin >> n;
    cin >> a >> b >> c;
    bmb.resize(n);
    for(int i = 0; i < n; i++){
        cin >> bmb[i];
    }

    vector<int> A;
    ans = 900000000;
    dfs(A);
    cout << ans << endl;

    return 0;
}