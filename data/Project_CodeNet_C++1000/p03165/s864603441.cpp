#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short

#define pb push_back

#define fst first
#define snd second
#define mp make_pair

#define MOD 1000000007
#define all(v) (v).begin(),(v).end()
#define frl(i,n) for(long long i=0;i<n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cerr << #x << " = " << x << "\n"
#define displayvec(vec) cerr<<#vec<<": "; for(auto vd : vec) cerr<<vd<<" "; cerr<<"\n"

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for(auto &i : v) cin>>i;
  return is;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for(auto &i : v) cout<<i<<" ";
  return os;
}

vector< ll > lis(vector< ll > &v){
    ll n = v.size();
    if(n == 0) return vector< ll > ();
    vector< ll > arr, temp(n + 1, LLONG_MAX);
    vector< ll > mark(n);

    for(ll i = 0; i < n; ++i){
        ll index = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
        mark[i] = index;
        temp[index] = v[i];
    }

    ll findex;
    for(findex = 0; temp[findex + 1] != LLONG_MAX; ++findex);

    for(ll i = n-1; i >= 0; --i){
        if(mark[i] == findex){
            arr.emplace_back(v[i]);
            --findex;
        }
    }
    reverse(arr.begin(), arr.end());
    return arr;
}

string lcs(string s, string t){
    string str;
    ll n = s.length(), m = t.length();
    vector< ll > arr[128];
    vector< ll > find_lis;
    //find_lis.reserve(n*m);

    for(ll i = 0; i < m; ++i){
        arr[static_cast< int >(t[i])].emplace_back(i);
    }
    for(auto &i : s){
        for(vector< ll > :: reverse_iterator itr = arr[static_cast< int >(i)].rbegin(); itr != arr[static_cast< int >(i)].rend(); ++itr){
            find_lis.emplace_back(*itr);
        }
    }

    const vector< ll > found_lis = lis(find_lis);
    for(auto i : found_lis){
        str.push_back(t[i]);
    }
    return str;
}

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin>>s>>t;
    cout<<lcs(s, t)<<"\n";
    return 0;
}
