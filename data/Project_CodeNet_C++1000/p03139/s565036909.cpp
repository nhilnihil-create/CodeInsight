#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n))
#define Vec(a,n) vector<string> (a)((n))
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0))
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0))
#define P pair<int,int>
#define All(a) (a).begin(),(a).end()
#define Sort(a) sort(All(a))
#define Reverse(a) reverse(All(a))
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
using namespace std;
int max_int = 1000000007;
void Debug(auto a);


signed main(){
    int n,a,b;
    cin >> n >> a >> b;
    int m = 0;
    cout << min(a,b) << " " << max(m,a+b-n) << endl;
    
    return 0;
}



void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}