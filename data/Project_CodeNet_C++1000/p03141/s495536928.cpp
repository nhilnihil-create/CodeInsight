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
    vector<array<int,2>> a,b;
    REP(i,n) {
        a.push_back({A[i]+B[i],i});
        b.push_back({B[i]+A[i],i});
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long long sum=0;
    REP(i,n) {
        if ( i%2 ) {
            while ( used[b.back()[1]] ) b.pop_back();
            int j=b.back()[1];
            used[j]=1;
            sum-=B[j];
            b.pop_back();
        } else {
            while ( used[a.back()[1]] ) a.pop_back();
            int j=a.back()[1];
            used[j]=1;
            sum+=A[j];
            a.pop_back();
        }
    }
    cout << sum << '\n';
    return 0;
}

