#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<int(n); i++)
using namespace std;

const int N=1e5+5;
int A[N],B[N];
bool used[N];
int main() {
    int n;
    cin >> n;
    REP(i,n) cin >> A[i] >> B[i];
    vector<array<int,2>> a;
    REP(i,n) {
        a.push_back({A[i]+B[i],i});
    }
    sort(a.begin(),a.end());
    long long sum=0;
    REP(i,n) {
        while ( used[a.back()[1]] ) a.pop_back();
        int j=a.back()[1];
        used[j]=1;
        a.pop_back();
        if ( i%2 ) {
            sum-=B[j];
        } else {
            sum+=A[j];
        }
    }
    cout << sum << '\n';
    return 0;
}

