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
    int r; cin >> r;
    if(r<1200) cout << "ABC";
    else if(r<2800) cout << "ARC";
    else cout << "AGC";
    cout << endl;
    return 0;
}