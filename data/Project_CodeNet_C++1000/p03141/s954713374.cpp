#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<int(n); i++)
using namespace std;

const int N=1e5+5;
int A[N],B[N];
bool used[N];
int main() {
    int n;
    cin >> n;
    REP(i,n) scanf("%d %d", A+i,B+i);
    vector<int> a;
    long long sum=0;
    REP(i,n) {
        a.push_back(A[i]+B[i]);
        sum+=A[i];
    }
    sort(a.begin(),a.end());
    for ( int i=n-2; i>=0; i-=2 ) {
        sum-=a[i];
    }
    cout << sum << '\n';
    return 0;
}

