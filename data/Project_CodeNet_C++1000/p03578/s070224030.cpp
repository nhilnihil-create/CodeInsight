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
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    int N,M;
    cin >> N;
    vll D(N);
    cin >> D;
    cin >> M;
    vll T(M);
    cin >> T;
    sort(D.begin(),D.end());
    sort(T.begin(),T.end());
    queue<ll> d,t;
    for(auto i:D)d.push(i);
    for(auto i:T)t.push(i);
    while(!d.empty() && !t.empty()){
        if(t.front() == d.front()){
            t.pop();
        }
        d.pop();
    }
    if(t.empty()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}