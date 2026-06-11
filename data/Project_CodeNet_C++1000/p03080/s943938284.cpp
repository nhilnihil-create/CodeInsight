#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define __m int mid=(l+r)>>1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

template<class T>
inline bool rd(T &num) {
    char in;bool IsN = false;
    while(in = getchar(), in != '-' && (in < '0' || in > '9'))if(in == EOF)return false;
    in == '-' ? (IsN = true, num = 0) : num = in - '0';
    while(in = getchar(), in >= '0' && in <= '9')num = num * 10 + in - '0';
    return IsN ? num = -num : num, true;
}
template<class T, class S>
inline bool rd(T &num1, S &num2){return rd(num1)&&rd(num2);}
template<class T, class S, class Z>
inline bool rd(T &num1, S &num2, Z &num3){return rd(num1)&&rd(num2)&&rd(num3);}
template<class T>
inline void _wr(T num){if(num>9)_wr(num/10);putchar('0'+num%10);}
template<class T>
inline void wr(T num){if(num < 0)putchar('-'),num=-num;_wr(num);}

void debug_out(){cerr<<endl;}
string to_string(string s){return '\"'+s+'\"';}
string to_string(char* s){return to_string((string)s);}
string to_string(bool s){return s?"true":"false";}
template<class T>
string to_string(T array);
template<class T,class S>
string to_string(pair<T,S>s){return '('+to_string(s.first)+','+to_string(s.second)+')';}
template<class T>
string to_string(T array){
    bool first=true;string res="[";
    for(const auto&e : array){
        if(!first)res+=",";first=false;res+=to_string(e);
    }
    return res+=']';
}
template<class Head, class... Tail>
void debug_out(Head H, Tail... T) {cerr << " " << to_string(H);debug_out(T...);}

string nico = "NicoNicoNi";
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define infile(x) freopen(x,"r",stdin)
#define outfile(x) freopen(x,"w",stdout)
#define io ios::sync_with_stdio(0)
#else
#define debug(...)
#define infile(x)
#define outfile(x)
#define io ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#endif

#define rep(a,b,c) for(register int (a)=(b);(a)<(c);++(a))
#define per(a,b,c) for(register int (a)=(b);(a)>=(c);--(a))
#define none(a) memset(a,-1,sizeof(a))
#define clr(a) memset(a,0,sizeof(a))
#define inf(a) memset(a,0x3f,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define space putchar(' ')
#define enter puts("")
#define endl '\n'
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define lowbit(x) (x&-x)

const int maxn = 26000;
const int inf  = 0x3f3f3f3f;
const ll  linf  = (1ll*inf)<<32|inf;
const int mod  = 1e9 + 7;
const int none = -1;
const double eps = 1e-7;


int main(){
    io;
    int n;
    cin>>n;
    int tot=0;
    string in;
    cin>>in;
    rep(i,0,n){
        if(in[i]=='R')
            tot++;
    }
    if(tot>n-tot)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
