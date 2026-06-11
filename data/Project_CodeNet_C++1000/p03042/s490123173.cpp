#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i, s, n) for(long long i=(s);i<(long long)(n);i++)
#define repi(i, n) for(int i=0;i<(int)(n);i++)
#define rep2i(i, s, n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(), v.end()

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

const ll INF = (1LL<<60);
const int INFi = (1<<29);

int main(){

    string s; cin >> s;

    ll a = (s[0]-'0')*10 + (s[1]-'0');
    ll b = (s[2]-'0')*10 + (s[3]-'0');

    if(((a>=1 && a<=12) && (b>=0 && b<=99)) && ((b>=1 && b<=12) && (a>=0 && a<=99))){
        cout << "AMBIGUOUS" << endl;
    }
    else if((a>=1 && a<=12) && (b>=0 && b<=99)){
        cout << "MMYY" << endl;
    }
    else if((b>=1 && b<=12) && (a>=0 && a<=99)){
        cout << "YYMM" << endl;
    }
    else{
        cout << "NA" << endl;
    }
    
    return 0;
}