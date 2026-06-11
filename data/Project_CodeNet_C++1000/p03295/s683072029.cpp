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
    int N, M;
    cin >> N >> M;
    vector<iint> A(M+1);
    for (int i = 0; i < M; i++) {
        cin >> A[i].second >> A[i].first;
        A[i].second--;
        A[i].first--;
    }
    A[M].first = N+1;
    A[M].second = N;
    sort(ALL(A));
    vector<int> c(N, 0);
    for (int j = A[0].first; j <= A[1].first; j++) {
        c[j] = 1;
    }
    for (int i = 1; i < M; i++) {
        if(c[A[i].first] == c[A[i].second]){
            c[A[i].first] = c[A[i].first] + 1;
            for (int j = A[i].first + 1; j <= min(A[i+1].first, N-1); j++) {
                c[j] = c[j-1];
            }
        }
        else{
            for (int j = A[i].first + 1; j <= min(A[i+1].first, N-1); j++) {
                c[j] = c[j-1];
            }
        }
    }
    printf("%d\n", c[N-1]);

}