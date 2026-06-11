#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

bool comp(int a, int b){
    return (a<b);
}

int main(){
    int n = 3; vector<int> a(n);
    REP(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[0]+a[1]+a[2]*10 << endl;
    return 0;
}