#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int main (){
    int N;
    cin >> N;

    
    vector<vector<int>> A(N,vector<int> (2));
    int B[N][2];
    rep(i,0,N) {
        cin >> A[i][0];
        A[i][1] = i;
        B[i][0] = A[i][0];
    }
    
    sort(A.begin(),A.end());

    rep(i,0,N) {
        if (i<=N/2-1) {
            B[A[i][1]][1] = A[N/2][0];
        }
        else {
            B[A[i][1]][1] = A[N/2-1][0];
        }

    }
    rep(i,0,N) {
        cout << B[i][1] << endl;
    }

}



