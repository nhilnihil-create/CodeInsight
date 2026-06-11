#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define SIZE(x) ll(x.size()) 

#define MOD 1000000007

int main(void)
{
    string S;
    ll A,B,C,D;
    cin >> S;
    A = S[0] - '0';
    B = S[1] - '0';
    C = S[2] - '0';
    D = S[3] - '0';

    char ope1,ope2,ope3;

    REP (i,8) {
             if (A + B + C + D == 7) { ope1 = '+'; ope2 = '+'; ope3 = '+'; } 
        else if (A - B + C + D == 7) { ope1 = '-'; ope2 = '+'; ope3 = '+'; }
        else if (A + B - C + D == 7) { ope1 = '+'; ope2 = '-'; ope3 = '+'; }
        else if (A - B - C + D == 7) { ope1 = '-'; ope2 = '-'; ope3 = '+'; }
        else if (A + B + C - D == 7) { ope1 = '+'; ope2 = '+'; ope3 = '-'; }
        else if (A - B + C - D == 7) { ope1 = '-'; ope2 = '+'; ope3 = '-'; }
        else if (A + B - C - D == 7) { ope1 = '+'; ope2 = '-'; ope3 = '-'; }
        else if (A - B - C - D == 7) { ope1 = '-'; ope2 = '-'; ope3 = '-'; }
        else { cout << "error" << endl;}
    }

    cout << A << ope1 << B << ope2 << C << ope3 << D << "=7" << endl;

    return 0;
}
