#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
 
int main(){

    string S;
    cin >> S;
    ll flaga=0;
    ll flagb=0;
    ll a=S.at(0)-'0';
    ll b=S.at(1)-'0';
    ll c=S.at(2)-'0';
    ll d=S.at(3)-'0';
    ll e=10*a+b;
    ll f=10*c+d;
    if(e<=12 && 1<=e) flaga=1;
    if(f<=12 && 1<=f) flagb=1;
    if(flaga==1 && flagb==1) cout << "AMBIGUOUS" << endl;
    else if(flaga==1) cout << "MMYY" << endl;
    else if(flagb==1) cout << "YYMM" << endl;
    else{
        cout << "NA" << endl;
    }
}
