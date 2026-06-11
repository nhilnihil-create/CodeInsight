/***
        ***Fresher***
    Md Mahfujur Rahman Khan
    Dept. of CSE
    CSE-28 Batch
    JU-48 Batch
    Jahangirnagar University

***/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<functional>
#include<set>
#include<map>
#include<climits>
#include<numeric>
#include<utility>
using namespace std;
#define V_ vector
#define Q_ queue
#define S_ set
#define ST_ stack
#define M_ map
#define DQ_ deque
/***PAIR***/
#define pii pair<ll,ll>
#define pci pair<char,ll>
#define psi pair<string, ll>
#define pis pair<ll,string>
#define pic pair<ll, char>
/***MAP***/
#define mii map<ll,ll>
#define msi map<string, ll>
#define mis map<ll, string>
#define mib map<ll,bool>
#define msb map<string,bool>
#define mci map<char, ll>
/***VECTOR***/
#define vl vector<ll>
#define vs vector<string>
/***ITERASTORS***/
#define ivi vector<ll> :: iterator
#define ivs vector<string> :: iterator
#define imii map<ll,ll> :: iterator
#define imsi map<string,ll> :: iterator
#define imis map<ll, string> :: iterator
#define imib map<ll, bool> :: iterator
#define imsb map<string, bool> :: iterator
#define imci map<char, ll> :: iterator
/*** FAST ***/
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
/***FUNCTIONS AND MACROS***/
#define F first
#define S second
#define M_P(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define PP(x) push(x)
#define RSZ(n) resize(n)
#define POB pop_back()
#define P_ pop()
#define CL_ clear()
#define LEN_ length()
#define SZ_ size()
#define CNT(x) count(x)
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define B_ begin()
#define E_ end()
#define F_ front()
#define t_ top()
#define IN_ insert
#define ER_  erase
#define GT(x) getline(cin , x)
#define NL_   "\n"
#define SP_ " "
#define R_0 return 0
#define R_ return

#define ul unsigned long long int
#define ll long long int
/***
//prime fact
#define most_prime_loop 1001
#define most_prime_number 2000010
#define prime_MAX_arr 2000010/2
ll PRIME[prime_MAX_arr];
void seive()
{
    PRIME[0] = 0;
    for(auto &x: PRIME )
        x = 1;
    for(ll i= 3; i <= most_prime_loop; i+=2)
    {
    if(PRIME[i/2]==0)
        for(ll j = i*i; j <= most_prime_number; j+=2*i)
            PRIME[j/2] = 0;
    }
}
***/

ll toteint (ll n)
{
    /**
       toteint(12)=4
       toteint(21)=12
       toteint(123456)=41088
    **/
    if(n < 2) return 0LL;
    ll temp = n;
    ll i = 2;
    ll res = n;
    if(n%i==0)
    {
        while(!(n%i))
            n/=i;
        res -= res/i;
    }
    i++;
    while(i <=(ll)sqrt(temp))
    {
        if(!(n%i))
        {
            while(!(n%i))
                n/=i;
            res-=res/i;
        }
        i+=2;
    }
    if(n>1)
        res -= res/n;
    return res;
}

#define fr(i, n) for( ll i = 0; i < n; i++)
#define fe(x, n) for( ll i = x; i <= n; i++)
#define fa(x,a)    for(auto &x : a)

#define pi acos(-1)

#define SR(x) sqrt(x)
#define IC   (ll)

const ll  inf = 2000000;
ll i=0, T=0, N=0, tc =0, t= 0;
ll n=0, k=0;
string s;

bool eq(ll n)
{
    ll s = 0, f =0;
    while(n)
    {
        if(n%10==4) f++;
        else s++;
        n/=10;
    }
    return f==s;
}


int main()
{
   ll sum = 0;
   ll n, r;
   cin >> n;
   ll mx = LLONG_MIN;
   while(n--)
   {
       cin >> r;
       sum+=r;
       mx = max(mx,r);
   }
   cout << sum-mx/2;
}
