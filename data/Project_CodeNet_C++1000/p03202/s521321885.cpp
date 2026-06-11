#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


template< typename T >
struct SparseTable {
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable(const vector< T > &v) {
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return min(st[b][l], st[b][r - (1 << b)]);
  }
};

int n;
bool f(int k,SparseTable<int> &st,vector<int> &a){
    unordered_map<int,P> ma;
    int bf = 0;
    for (int i = 0; i < n; i++) {
        int t = a[i];
        if(ma.find(t) != ma.end()){
            if(st.rmq(ma[t].sc,i) < t) ma[t] = mp(0,i);
        }
        if(t < bf && ma[t].fs == 0) ma[t] = mp(1,i); 
        ma[t].fs++;
        ma[t].sc=i;
        while(ma[t].fs == k + 1){
            ma[t].fs = 1;
            if(ma.find(t-1) != ma.end()){
                if(st.rmq(ma[t-1].sc,i) < t - 1) ma[t - 1] = mp(1,i);
                else ma[t - 1].sc = i;
            }
            else ma[t - 1] = mp(1,i);
            ma[t-1].fs++;
            t--;
            if(t<=0||k==1) return false;
        }
        bf = a[i];
    }
    return true;
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SparseTable<int> st(a);
    int l = 0, r = INF;
    while(abs(r - l) > 1){
        int m =  l + (r - l) / 2;
        if(f(m,st,a)) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}
