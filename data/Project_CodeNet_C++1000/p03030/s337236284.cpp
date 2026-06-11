#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
int main()
{
    int N;
    cin >> N;
    vector<pair<string,int>> book;
    map<pair<string,int>,int> mp;
    REP(i,N){
        string s;
        int p;
        cin >> s >> p;
        mp[make_pair(s,p)] = i+1;
        book.pb(make_pair(s,abs(p-100)));
    }
    sort(book.begin(),book.end());
    for(auto b : book){
        cout << mp[make_pair(b.first,100-b.second)] << endl;
    }
}