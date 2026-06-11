#include <bits/stdc++.h>


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

#define X real()
#define Y imag()

using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
using ll  = long long;

using point = complex<double>;


void err(istream_iterator<string> it) {cerr << endl;}
template<typename T, typename... Args>void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << " = " << a << endl;err(++it, args...);}


const double EPS = 1e-8;
const long long mod = 1e9+7;

const int dx[] = {0, 0,1,-1,1,-1, 1,-1};
const int dy[] = {1,-1,0, 0,1,-1,-1, 1};

const int N = 1e5 + 5;


int n , m,arr[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
            cin >> arr[i];
    map<int,int> frq;
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        arr[i] = (arr[i]%m + arr[i - 1]%m)%m;

        ans += (arr[i]==0);
        ans += frq[arr[i]];
        frq[arr[i]]++;
    }
    cout << ans << '\n';

    return 0;
}
