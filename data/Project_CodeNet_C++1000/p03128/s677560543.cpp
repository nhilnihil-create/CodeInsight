#include<bits/stdc++.h>
using namespace std;
#define p pair<int,int>
int N, M;
char A[10];
int num[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string dp[10010];

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> A[i];
        if(dp[num[A[i] - '0']] == ""){
            dp[num[A[i] - '0']] = A[i];
        }else if(dp[num[A[i] - '0']][0] - '0' < A[i] - '0'){
            dp[num[A[i] - '0']] = A[i];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(dp[i] == "") continue;
            string str1 = dp[i] + A[j];
            string& str2 = dp[i + num[A[j] - '0']];
            if(str2.size() < str1.size()){
                str2 = str1;
            } else if(str2.size() == str1.size()){
                for(int k = 0; k < str1.size(); k++){
                    if(str2[k] - '0' > str1[k] - '0') break;
                    else if(str2[k] - '0' < str1[k] - '0'){
                        str2 = str1;
                        break;
                    }
                }
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}