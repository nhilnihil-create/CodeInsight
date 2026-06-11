#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(10, 0); int tmp;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        A[tmp] = 1;
    }
    if(A[5] == 1){
        A[2] = 0; A[3] = 0;
    }
    if(A[3] == 1){
        A[2] = 0;
    }
    if(A[9] == 1){
        A[6] = 0;
    }
    
    vector<int> a, AA;
    vector<int> match(10);
    match[1] = 2;
    match[2] = 5;
    match[3] = 5;
    match[4] = 4;
    match[5] = 5;
    match[6] = 6;
    match[7] = 3;
    match[8] = 7;
    match[9] = 6;

    for (int i = 1; i < 10; i++) {
        if(A[i] == 1){
            a.push_back(match[i]);
            AA.push_back(i);
        }
    }

    sort(ALL(AA), greater<int> ());    

    vector<int> dp(N+1, -inINF);
    dp[0] = 0; 
    for (int i = 1; i < N+1; i++) {
        tmp = -inINF;
        for (int j : a){
            if(i - j >= 0){
                tmp = max(tmp, dp[i-j] + 1);
            }
        }
        dp[i] = tmp;
    }

    tmp = N;
    for (int i = 0; i < dp[N]; i++) {
        for (int v : AA) {
            if(tmp - match[v] >= 0 && dp[tmp]-1 == dp[tmp - match[v]]){
                printf("%d", v);
                tmp -= match[v];
                break;
            }
        }
    }

    cout << endl;

    


}