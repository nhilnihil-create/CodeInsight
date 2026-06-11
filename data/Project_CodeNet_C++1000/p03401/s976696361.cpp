#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int N; cin >> N;
    vector <int> A(N+2);
    A[0]=0;
    A[N+1]=0;
    for (int i=1; i<=N; i++) cin >> A[i];
    
    ll sum=0;
    rep(i,N+2) sum+=abs(A[i+1]-A[i]);
    
    for (int i=1; i<=N; i++){
        cout << sum -( abs(A[i]-A[i-1]) + abs(A[i+1]-A[i]) )+ abs(A[i+1]-A[i-1]) << endl;
    }
}