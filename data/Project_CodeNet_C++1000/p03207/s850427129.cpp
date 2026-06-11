#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
typedef long long ll;

using namespace std;

int main() {

    cin.tie(0);
	ios::sync_with_stdio(false);

    int N;
    cin>>N;
    int a[10]={0};
    REP(i,N){
        cin>>a[i];
    }
    sort(a,a+N,greater<int>());
    int ans=0;
    REP(i,N){
        if(i==0)ans+=a[i]/2;
        else ans+=a[i];
    }
    cout<<ans<<endl;
}

/*
g++ code.cpp
./a.out
*/