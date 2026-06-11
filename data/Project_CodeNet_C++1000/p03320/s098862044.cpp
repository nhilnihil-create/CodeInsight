#include <bits/stdc++.h>
using namespace std;



#define REP(i, x)   for (__typeof(x) i = 0; i < x; i++)
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define repi(i, x)  for (__typeof(x) i = x-1; i >= 0; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    VI;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
typedef vector<vector<int>> VVI;
const   int            infi = numeric_limits<int>::max();
const   double         eps = 0;
const   int            ms  = 0;

double func(ll a_){
    ll a = a_;
        ll s = 0;
        while(a>0){
            s+=a%10;
            a = a/10;
        }
        return (double)a_/s;
}
int main(){
    long long k;
    
    cin >> k ;
    vector<ll> c;
    vector<double> fs;
    for(int i = 0; i < 9; i++){
        c.push_back(i+1);
        fs.push_back(func(i+1));
    }
    for(int i = 19; i < 100LL; i+=10){
        c.push_back(i);
        fs.push_back(func(i));
    }
    ll a = 1;

    for(ll ke = 3; ke <=15; ke++){
        for(ll i = 101; i <= 1000; i++){
            c.push_back(i*a-1);
            fs.pb(func(i*a-1));
        }
        a*=10;
    }

    ll n = 0;
    for(int i = 0; i < c.size(); i++){
        double f = fs[i];
        bool b = true;
        //cout << c[i] <<" "<< fs[i] << endl;
        for(int j = i+1; j < c.size(); j++){
            if(f > fs[j]){
                //cout << fs[i] << endl;
                b = false;
                break;
            }
        }
        //if(b && n < k)cout << c[i] << " " << fs[i] << "sunuke" <<endl;
        if(b && n < k){cout << c[i] <<endl;
        
        n++;}
        //else cout << c[i] << " " << fs[i] <<endl;
    }

    return 0;
}