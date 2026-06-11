// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A;
    string S;
    cin >> S;
    S += ' ';
    int first = S[0] - '0', index = 0;

    while(index < N){
        int tmp = 1;
        while(S[index] == S[index + 1]){
            tmp++;
            index++;
        }
        A.push_back(tmp);
        index++;
    }

    vector<int> sum(A.size() + 1, 0);

    for(int i = 1; i <= A.size(); i++){
        sum[i] = sum[i - 1] + A[i - 1];
    }

    int ans = 0;
    if(first == 1){
        for(int i = 1; i <= A.size(); i += 2){
            int j = i + 2 * K;
            bool flag = false;
            if(j > A.size()){
                j = A.size();
                flag = true;
            }
            ans = max(ans, sum[j] - sum[i - 1]);
            if(flag) break;
        }
    } else {
        for(int i = 0; i <= A.size(); i += 2){
            int j = i + 2 * K;
            bool flag = false;
            if(j > A.size()){
                j = A.size();
                flag = true;
            }
            if(i == 0 ) ans = sum[j];
            else ans = max(ans, sum[j] - sum[i - 1]);
            if(flag) break;
        }
    }

    cout << ans << endl;



}