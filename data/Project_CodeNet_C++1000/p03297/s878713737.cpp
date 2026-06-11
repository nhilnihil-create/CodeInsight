#include                          <bits/stdc++.h>
#define     lli                   unsigned long long int
#define     ll                    long long int
#define     PI                    acos(-1.0)
#define     UNIQUE(V)             (V).erase(unique(ALL(V), (V).end()) //vector/string etc must need to be sorted
#define     timesave              ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define     ALL(V)                (V).begin(), (V).end()
#define     MEMSET(a, val)        memset(a, val, sizeof(a))
#define     FILE_INPUT            freopen("input.txt", "r", stdin) , freopen("output.txt", "w", stdout)
#define     DEBUG                 printf("---- ekhane asi ekhon ---- \n");
#define     SQR(x)                ((x)*(x))
using       namespace             std;


template    <class T> T GCD(T a, T b) { return (b != 0 ? GCD <T> (b, a%b) : a); }
template    <class T> T LCM(T a, T b) { return ((a*b)  / GCD <T> (a, b)); }
template    <class T> T POW(T x, T n) { if(n == 0) return 1; if(n&1) return x*POW(x, n-1);  else return SQR(POW(x, n/2));}

long long   Bigmod(long long base, long long power, long long MOD) {long long ret = 1; while(power) {if(power & 1) ret = (ret*base)%MOD; base = (base*base)%MOD; power >>= 1;} return ret;}
bool        isVowel(char ch) {ch = toupper(ch); if(ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E') return true; return false;}
long long   ModInverse(long long number, long long MOD) {return Bigmod(number, MOD-2, MOD);}
bool        isConst(char ch) {if(isalpha(ch) && !isVowel(ch)) return true; return false;}
int         toInt(string s)  {int si; stringstream ss(s); ss >> si; return si;}

int dx[8] = { 0,  0,  1  -1,  1,  1, -1, -1};
int dy[8] = { 1, -1,  0,  0,  1, -1,  1, -1};


//------------------- Let`s Start ------------------------ //

bool myfunc(pair<char, char> &x, pair<char, char> &y)
{
    if(x.first == y.first || x.second == y.second) return true;
    else return false;
}


int main()
{
    timesave;

    ll t, a, b, c, d;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> a >> b >> c >> d;

        if(b > a || b > d) cout << "No" << endl;

        else if(c >= b) cout << "Yes" << endl;

        else{
            ll gcd = __gcd(b, d);
            ll res = b - gcd + (a%gcd);

            if(res > c) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }

	return 0;
}
