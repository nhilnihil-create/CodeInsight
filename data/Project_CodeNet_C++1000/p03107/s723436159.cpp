#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000000000000000;
//input
string S;


//processing
int A,B;


//dpTable
//int dp[100050];

int main(){
    cin >> S;
    for (int i = 0; i < S.size(); i++){
        if (S.at(i) == '0'){
            A++;
        }
        else {
            B++;
        }
    }
    cout << 2 * min(A,B) << endl;
    return 0;
}
