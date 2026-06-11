#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main(){cout<<fixed<<setprecision(20);
		   string s;
           cin>>s;
           bool ans=false;
           if(s=="AKIHABARA")ans=1;
           if(s=="AKIHABAR")ans=1;
           if(s=="AKIHABRA")ans=1;
           if(s=="AKIHABR")ans=1;
           if(s=="AKIHBARA")ans=1;
           if(s=="AKIHBAR")ans=1;
           if(s=="AKIHBRA")ans=1;
           if(s=="AKIHBR")ans=1;
           if(s=="KIHABARA")ans=1;
           if(s=="KIHABAR")ans=1;
           if(s=="KIHABRA")ans=1;
           if(s=="KIHABR")ans=1;
           if(s=="KIHBARA")ans=1;
           if(s=="KIHBAR")ans=1;
           if(s=="KIHBRA")ans=1;
           if(s=="KIHBR")ans=1;
           YES(ans);
}