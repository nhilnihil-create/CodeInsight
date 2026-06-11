#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int A,B,C;
    cin >> A >> B >> C;
    if(B < A)swap(A,B);
    if(C >= A && C <= B)cout << "Yes" << endl;
    else cout << "No" << endl;
}