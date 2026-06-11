#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

int GCD(long long a,long long b){
    if(a>b) swap(a,b);
    if(a==0) return b;
    return(GCD(b%a, a));
}

int main(){
    long long  N,M; cin >> N >> M;
    string S,T; cin >> S >> T;
    long long lens = S.size(); long long lent = T.size();
    long long g = GCD(lens, lent);
    long long ans = lens*lent/g;
    for(int i=0;i<g;i++){
        if(S[i*(lens/g)] != T[i*(lent/g)]) {ans = -1; break;}
    }
    cout << ans << endl;
}


