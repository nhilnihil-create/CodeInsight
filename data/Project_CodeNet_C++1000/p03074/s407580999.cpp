#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<int> vec_0(0);
    vector<int> vec_1(0);
    vec_0.push_back(0);
    vec_1.push_back(0);
    if (S[0] == '0') vec_0[0]++;
    if (S[0] == '1') vec_1[0]++;
    for (int i = 0; i < S.size() - 1; i++){
        if (S[i] == S[i + 1]){
            if (S[i] == '0') vec_0[vec_0.size() - 1]++;
            if (S[i] == '1') vec_1[vec_1.size() - 1]++;
        }
        else if (S[i] == '0'){
            if (vec_1[0] == 0) vec_1[0]++;
            else vec_1.push_back(1);
        }
        else if (S[i] == '1'){
            if (vec_0[0] == 0) vec_0[0]++;
            else vec_0.push_back(1);
        }
    }
    int ans = 0;
    int len_0 = vec_0.size();
    int len_1 = vec_1.size();
    if (len_0 < len_1){
        if (K >= len_0){
            ans = N;
        }
        else{
            int ans_sub = 0;
            rep(i,K){
                ans_sub += vec_0[i];
            }
            rep(i,K + 1){
                ans_sub += vec_1[i];
            }
            ans = max(ans,ans_sub);
            rep(i,len_0 - K){
                ans_sub -= vec_0[i];
                ans_sub -= vec_1[i];
                ans_sub += vec_0[i + K];
                ans_sub += vec_1[i + K + 1];
                ans = max(ans,ans_sub);
            }
        }
    }
    else if (len_0 > len_1){
        if (K >= len_0){
            ans = N;
        }
        else{
            vec_1.push_back(0);
            vec_1.insert(vec_1.begin(),0);
            int ans_sub = 0;
            rep(i,K){
                ans_sub += vec_0[i];
            }
            rep(i,K + 1){
                ans_sub += vec_1[i];
            }
            ans = max(ans,ans_sub);
            rep(i,len_0 - K){
                ans_sub -= vec_0[i];
                ans_sub -= vec_1[i];
                ans_sub += vec_0[i + K];
                ans_sub += vec_1[i + K + 1];
                ans = max(ans,ans_sub);
            }
        }
    }
    else if (S[0] == '0'){
        if (K >= len_0){
            ans = N;
        }
        else{
            vec_1.insert(vec_1.begin(),0);
            int ans_sub = 0;
            rep(i,K){
                ans_sub += vec_0[i];
            }
            rep(i,K + 1){
                ans_sub += vec_1[i];
            }
            ans = max(ans,ans_sub);
            rep(i,len_0 - K){
                ans_sub -= vec_0[i];
                ans_sub -= vec_1[i];
                ans_sub += vec_0[i + K];
                ans_sub += vec_1[i + K + 1];
                ans = max(ans,ans_sub);
            }
        }
    }
    else{
        if (K >= len_0){
            ans = N;
        }
        else{
            vec_1.push_back(0);
            int ans_sub = 0;
            rep(i,K){
                ans_sub += vec_0[i];
            }
            rep(i,K + 1){
                ans_sub += vec_1[i];
            }
            ans = max(ans,ans_sub);
            rep(i,len_0 - K){
                ans_sub -= vec_0[i];
                ans_sub -= vec_1[i];
                ans_sub += vec_0[i + K];
                ans_sub += vec_1[i + K + 1];
                ans = max(ans,ans_sub);
            }
        }
    }
    cout << ans << endl;
}