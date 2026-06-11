#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1,INF);
    
    vector<int> B(1,1);
    int tmp = 1;
    while(tmp<=100000) {
        tmp*=6;
        B.push_back(tmp);
    }
    tmp = 1;
    while(tmp<=100000) {
        tmp*=9;
        B.push_back(tmp);
    }
    A[0] = 0;
    rep(i,N+1) {
        if (i==0) continue;
        for(auto b:B) {
            if (i-b>=0) {
                A[i] = min(A[i],A[i-b]+1);
            }
        }
    }
    int ans = A[N];
    cout << ans << endl;
}
