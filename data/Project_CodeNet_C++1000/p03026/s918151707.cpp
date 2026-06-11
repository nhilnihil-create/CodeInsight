#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

const int N_MAX = 10050;
vector<int> c;
vector<vector<int>> a(N_MAX);
vector<int> v_sc(N_MAX);
vector<bool> visited(N_MAX);
void bfs(int v){
    queue<int> q;
    q.push(v);
    int it = 0;
    visited[0] = true;
    while(!q.empty()){
        int nq = q.front(); q.pop();
        for(int next: a[nq]){
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
        //cout << nq <<":" <<it << endl;
        v_sc[nq] = c[it++];
    }

}

int main()
{
    int n;
    cin >> n;
    rep(i, n-1){
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        tmp1--; tmp2--;
        a[tmp1].push_back(tmp2);
        a[tmp2].push_back(tmp1);
    }
    rep(i, n) { 
        int tmp;  cin >> tmp; c.push_back(tmp);
    }
    sort(c.begin(), c.end(), greater<int>());
    bfs(0);
    
    int c_sum = 0;
    rep1(i, n-1){
        c_sum += c[i];
    }

    cout << c_sum << endl;
    rep(i, n){
        cout << v_sc[i] << " "; 
    }
    cout << endl;
}

