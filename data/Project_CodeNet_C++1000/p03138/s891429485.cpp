/// *********** Coded by Olium_MdioxideN ***********

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ext exit(0)
#define fast ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define in_file freopen("input.txt", "r", stdin)
#define out_file freopen("output.txt", "w", stdout)
#define newl printf("\n")
#define nl '\n'
#define endl '\n'
#define sci(x) scanf("%d",&(x))
#define scll(x) scanf("%lld",&(x))
#define sci2(x,y) scanf("%d %d",&(x),&(y))
#define pr printf
#define forr(i,b,e) for(int (i)=(b); (i) <= (e); (i)++)
#define fors(i,x) for(auto (i)=(x).begin(); (i) != (x).end(); (i)++)
#define F first
#define S second
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
#define bs binary_search
#define all(x) (x).begin(),(x).end()
#define pqmin(x) priority_queue<x, vector<x>, greater<x> >
#define pqmax(x) priority_queue<x>
#define sortd(x) sort(all(x)); reverse(all(x));
#define vi vector<int>
#define pii pair<int,int>
#define mpii map<int,int>
#define elif else if
#define debug(x) cerr << "Debug: " << x << '\n';
#define pi 3.14159265358979323846D
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) __lcm(x,y)
#define runtime() cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
#define Int inputInt()        //new int input
#define Long inputLong()      //new long input
#define Double inputDouble()  //new double input
#define String inputString()  //new string input
inline int inputInt() { int tmp; scanf(" %d", &tmp); return tmp; }
inline ll inputLong() { ll tmp; scanf(" %lld", &tmp); return tmp; }
inline double inputDouble() { double tmp; scanf(" %lf", &tmp); return tmp; }
inline string inputString() { char tmpStr[1000010]; scanf(" %s", tmpStr); return tmpStr; }

template <typename type> inline type __lcm(type n1,type n2){ return n1*(n2/gcd(n1,n2)); }

class stdout_cus
{
    short float_prec = 7;
public:
    inline stdout_cus operator<<(const int& arg){ printf("%d",arg); return *this; }
    inline stdout_cus operator<<(const short& arg){ printf("%d",arg); return *this; }
    inline stdout_cus operator<<(const bool& arg){ printf("%d",arg); return *this; }
    inline stdout_cus operator<<(const unsigned int& arg){ printf("%u",arg); return *this; }
    inline stdout_cus operator<<(const unsigned short& arg){ printf("%u",arg); return *this; }
    inline stdout_cus operator<<(const long long& arg){ printf("%lld",arg); return *this; }
    inline stdout_cus operator<<(const unsigned long long& arg){ printf("%llu",arg); return *this; }
    inline stdout_cus operator<<(const double& arg){ printf("%.*f",float_prec,arg); return *this; }
    inline stdout_cus operator<<(const float& arg){ printf("%.*f",float_prec,arg); return *this; }
    inline stdout_cus operator<<(const char& arg){ printf("%c",arg); return *this; }
    inline stdout_cus operator<<(const unsigned char& arg){ printf("%c",arg); return *this; }
    inline stdout_cus operator<<(const char* arg){ printf("%s",arg); return *this; }
    inline stdout_cus operator<<(const std::string& arg){ printf("%s",arg.c_str()); return *this; }
    inline stdout_cus operator<<(const stdout_cus&){ return *this; }
    inline void flush() { fflush(stdout); }
    inline stdout_cus precision(short prec) { float_prec = prec; return *this; }
}cout_cus;
class stdin_cus
{
public:
    inline stdin_cus operator>>(const int& arg){ scanf(" %d",&arg); return *this; }
    inline stdin_cus operator>>(const short& arg){ scanf(" %d",&arg); return *this; }
    inline stdin_cus operator>>(const bool& arg){ scanf(" %d",&arg); return *this; }
    inline stdin_cus operator>>(const unsigned int& arg){ scanf(" %u",&arg); return *this; }
    inline stdin_cus operator>>(const unsigned short& arg){ scanf(" %u",&arg); return *this; }
    inline stdin_cus operator>>(const long long& arg){ scanf(" %lld",&arg); return *this; }
    inline stdin_cus operator>>(const unsigned long long& arg){ scanf(" %llu",&arg); return *this; }
    inline stdin_cus operator>>(const double& arg){ scanf(" %lf",&arg); return *this; }
    inline stdin_cus operator>>(const float& arg){ scanf(" %f",&arg); return *this; }
    inline stdin_cus operator>>(const char& arg){ scanf(" %c",&arg); return *this; }
    inline stdin_cus operator>>(const unsigned char& arg){ scanf(" %c",&arg); return *this; }
    inline stdin_cus operator>>(const char* arg){ scanf(" %s",arg); return *this; }
    inline stdin_cus operator>>(std::string& arg){ char tmp[1000000]; scanf(" %s",tmp); arg = tmp; return *this; }
    inline void flush() { fflush(stdin); }
}cin_cus;
#define cout cout_cus
#define cin cin_cus
#define sp cout.precision

/// * * *    Main Code Starts Now    * * *

#define MOD 10000007
#define MAX 100010
void olium();
int main()
{
    //#ifndef ONLINE_JUDGE
    //in_file;
    //out_file;
    //#endif
    int t = 1;
    //cin >> t;
    forr(i,1,t)
    {
        //cout << "Case " << i << ": ";
        olium();
    }
    return 0;
}

void olium()
{
    int n;
    ll k;
    cin >> n >> k;
    ll a[n+1];
    forr(i,1,n)
    {
        cin >> a[i];
    }
    int bincnt[41] = {0};
    forr(i,0,40)
    {
        forr(j,1,n)
        {
            bincnt[i] += (bool)(a[j] & (1LL << i));
        }
    }
    bool khaisi = false;
    for(int i = 40; i >= 0; i--)
    {
        if(khaisi)
        {
            bool one = false;
            if(bincnt[i] < (n - bincnt[i])) one = true;
            if(!one)
            {
                k = k & (~(1LL << i));
            }
            else k = k | (1LL << i);
        }
        else if(k & (1LL << i))
        {
            bool one = false;
            if(bincnt[i] < (n - bincnt[i])) one = true;
            if(!one)
            {
                k = k & (~(1LL << i));
                khaisi = true;
            }
        }
    }
    ll sum = 0;
    forr(i,1,n)
    {
        sum += (k ^ a[i]);
    }
    cout << sum << nl; 
}