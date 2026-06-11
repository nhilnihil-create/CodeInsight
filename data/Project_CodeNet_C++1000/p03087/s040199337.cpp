#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main() {
    int N,Q; cin >> N >> Q;
    string S; cin >> S;
    vector<int> a(N);
    vector<int> c(N);
    int counta=0; int countc=0;
    for(int i=0;i<N;i++){
        if(S[i]=='A'&&S[i+1]=='C')counta++;
        if(S[N-1-i]=='C'&&S[N-2-i]=='A')countc++;
        a[i]=counta; c[N-1-i]=countc;
    }
    int SUM = counta;
    for(int i=0;i<Q;i++){
        int l,r; cin >> l >> r;
        cout << SUM-a[l-2]-c[r] << endl;
    }
}

