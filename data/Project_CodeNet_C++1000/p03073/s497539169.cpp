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




const int dx[] = {0, 0,1,-1,1,-1, 1,-1};
const int dy[] = {1,-1,0, 0,1,-1,-1, 1};

const double EPS = 1e-9;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
const int N = 3e5 + 5;




int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    int ans1 = 0 ,ans2 = 0;
    for(int i = 0; i < str.size(); ++i){
        if( (str[i]-'0') % 2 != i %2 )ans1++;
    }
    for(int i = 0; i < str.size(); ++i){
        if((str[i]-'0') % 2 == i % 2)ans2++;
    }
    cout << min(ans1,ans2) << '\n';
    return 0;
}
