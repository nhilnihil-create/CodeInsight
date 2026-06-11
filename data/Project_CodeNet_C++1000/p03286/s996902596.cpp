#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define DD double
#define Pb push_back
#define Bp pop_back
#define Pf push_front
#define Fp pop_front
#define Ub upper_bound
#define Lb lower_bound
#define In insert
#define All(x) x.begin(), x.end()
#define mem(a, b) memset(a, b, sizeof(a))
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define X first
#define Y second
#define mx1 10
#define mx2 110
#define mx3 1010
#define mx4 10010
#define mx5 100010
#define mx6 1000010

typedef vector<LL> Vl;
typedef vector<DD> Vd;
typedef vector<bool> Vb;
typedef vector<Vl> VVl;
typedef pair<LL, LL> Pll;
typedef pair<DD, DD> Pdd;
typedef vector<Pll> Vpl;
typedef vector<Pdd> Vpd;
typedef queue<LL> Ql;
typedef stack<LL> Sl;
typedef deque<LL> Dl;

LL _set(LL N, LL pos) {return N = N | (1 << pos);}
LL _reset(LL N, LL pos) {return N = N & ~(1 << pos);}
bool _check(LL N, LL pos) {return (bool)(N & (1 << pos));}
bool _upper(char a) {return a >= 'A' && a <= 'Z';}
bool _lower(char a) {return a >= 'a' && a <= 'z';}
bool _digit(char a) {return a >= '0' && a <= '9';}

LL dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
LL dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

///**************************DONE****************************///

LL a[35], P[35], N[35];
vector<int> ans;

void pos(int n);
void neg(int n);

int main()
{
    for(int i = 0, j = 1; i <= 31; i++, j *= 2)
        a[i] = i % 2? -j: j;

    for(int i = 0; i <= 31; i++){
        if(a[i] > 0)
            P[i] = a[i];
        P[i] += P[i - 1];
        if(a[i] < 0)
            N[i] = a[i];
        N[i] += N[i - 1];
    }


    int n;
    cin >> n;

    if(!n)
        return cout << 0 << '\n', 0;

    if(n > 0)
        pos(n);
    else if(n < 0)
        neg(n);

    sort(All(ans));

    int it = 0, L = ans.size();
    string s;

    for(int i = 0; i <= 31; i++){
        if(i == ans[it]){
            s.Pb('1'), it++;
            if(it == L)
                break;
        }
        else
            s.Pb('0');
    }

    reverse(All(s));

    cout << s << '\n';
    return 0;
}

void pos(int n)
{
    for(int i = 0; i <= 31; i++){
        if(P[i] >= n){
            ans.Pb(i);
            int x = n - a[i];
            if(x > 0)
                pos(x);
            else if(x < 0)
                neg(x);
            return;
        }
    }
}

void neg(int n)
{
    for(int i = 0; i <= 31; i++){
        if(N[i] <= n){
            ans.Pb(i);
            int x = n - a[i];
            if(x > 0)
                pos(x);
            else if(x < 0)
                neg(x);
            return;
        }
    }
}

