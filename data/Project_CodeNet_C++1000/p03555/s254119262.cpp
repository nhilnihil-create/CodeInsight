#include <bits/stdc++.h>


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()


using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
using ll  = long long;

using point = complex<double>;


void err(istream_iterator<string> it) {cerr << endl;}
template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}


const double EPS = 1e-8;
const long long mod = 1e9 + 7;

const int dx[] = {0, 0,1,-1,1,-1, 1,-1};
const int dy[] = {1,-1,0, 0,1,-1,-1, 1};

const int N = 1e5 + 5;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str,s;
    bool can = 1;
    vector<string>a,b;
    for(int i = 0; i < 2; ++i){
        cin >> str;
        a.push_back(str);
        s = str;
        reverse(all(s));
        b.push_back(s);
    }
    swap(b[0],b[1]);
    if(a == b)can = 1;
    else can = 0;
    cout << (can ? "YES\n" : "NO\n");

    return 0;
}
