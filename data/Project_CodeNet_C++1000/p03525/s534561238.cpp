#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1);
    A[N] = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B(13,0);
    for (int i = 0; i < N; i++) {
        B[A[i]]++;
    }
    if(B[0] > 0){
        printf("0\n");
        return 0;
    }
    if(B[12] > 1){
        printf("0\n");
        return 0;
    }
    for (int i = 1; i < 12; i++) {
        if(B[i] > 2){
            printf("0\n");
            return 0;
        }   
    }

    vector<bool> ans(24, false);
    ans[0] = true;
    sort(ALL(A));
    A.erase(unique(ALL(A)), A.end());
    int L = A.size();
    // for (int i = 0; i < L; i++) {
    //     printf("%d\n", A[i]);
    // }
    for (int i = 1; i < L; i++) {
        if(B[A[i]] == 2){
            ans[A[i]] = true;
            ans[24-A[i]] = true;
        }
        else{
            if(ans[A[i-1]] == true){
                ans[24-A[i]] = true;
            }
            else{
                ans[A[i]] = true;
            }
        }
    }
    if(B[12] == 1){
        ans[12] = true;
    }

    int kotae = 24;
    int tmp = 0;
    for (int i = 1; i < 24; i++) {
        if(ans[i]){
            kotae = min(kotae, i - tmp);
            tmp = i;
        }
    }
    kotae = min(kotae, 24 - tmp);

    printf("%d\n", kotae);
    

}