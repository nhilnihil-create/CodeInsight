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
    int k; cin >> k;
    if(k%2==1) cout << (k/2)*(k/2+1);
    else cout << (k/2)*(k/2);
    cout << endl;
    return 0;
}