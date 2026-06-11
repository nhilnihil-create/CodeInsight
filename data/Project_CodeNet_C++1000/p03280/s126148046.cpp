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
    int a, b; cin >> a >> b;
    cout << (a*b)-a-b+1 << endl;
    return 0;
}