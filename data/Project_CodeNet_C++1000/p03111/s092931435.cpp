#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n));
#define Vec(a,n) vector<string> (a)((n));
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0));
#define P pair<int,int>
#define All(a) (a).begin(),(a).end()
#define Sort(a) sort(All(a));
#define Reverse(a) reverse(All(a));
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
#define print(a) cout << (a) << endl
#define printD(a) cout << setprecision(15) << (a) << endl;
using namespace std;
int max_int = 1000000007;
void Debug(auto a);
int nibul(auto a,auto b);
int nibuu(auto a,auto b);
void input(vector<auto>& a,int n);
double PI = 3.14159265358979;
int n;
int a,b,c;
vector<int> d;

int dfs(int n,int cnt,int A,int B,int C){
    if(n == cnt){
        if(min({A,B,C}) == 0){
            return max_int;
        }
        else return abs(A-a) + abs(B-b) + abs(C-c)-30;
    }
    int w = dfs(n,cnt+1,A,B,C);
    int x = dfs(n,cnt+1,A+d[cnt],B,C)+10;
    int y = dfs(n,cnt+1,A,B+d[cnt],C)+10;
    int z = dfs(n,cnt+1,A,B,C+d[cnt])+10;
    return min({w,x,y,z});
}

signed main(){
    cin >> n >> a >> b >> c;
    d.resize(n);
    input(d,n);
    print(dfs(n,0,0,0,0));

    return 0;
}

void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}

//key以上の初めてのitr
int nibul(auto a,auto b){return lower_bound(All(a),b) - a.begin();}
//key以下の最後のitr
int nibuu(auto a,auto b){return upper_bound(All(a),b) - a.begin()-1;}

void input(vector<auto>& a,int n){
    REP(i,n){
        cin >> a[i];
    }
}
