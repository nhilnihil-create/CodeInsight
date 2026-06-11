//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18) + 1;
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string s;
vector<int> a;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s;
    map<char,int>m;
    for (int i = 0; i <s.size(); i++)
    {
        m[s[i]]++;
    }
    for(char c='a';c<='z';c++){
        if(m[c]==0){
            s+=c;
            break;
        }
        if(c=='z'){
            map<char,int>m1;
            char temp=s[s.size()-1];
            m1[s[s.size()-1]]++;
            for (int i =s.size()-2; i >=0; i--)
                {
                    m1[s[i]]++;
                    if(temp>s[i]){
                        s[i]++;
                        while(m1[s[i]]==0){
                            s[i]++;
                        }
                        cout<<s.substr(0,i+1)<<"\n";
                        return 0;
                    }
                    temp=s[i];
                }
            return cout<<-1<<"\n",0;
        }
    }
    cout << s<< "\n";
}
