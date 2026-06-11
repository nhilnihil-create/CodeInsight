#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int ans = 0;
int N;

void dfs(vector<int> &a, vector<int> &b) {
    if (b.size() == N) {
        bool tmp = false;
        rep(i,0,N) {
            if (b[i]%2==0) {
                tmp = true;
                break;
            }
        }
        if (tmp) {
            ans++;
        }
    }
    else {
        
        rep(i,a[b.size()]-1,a[b.size()]+2) {
            b.push_back(i);
            dfs(a,b);
            b.pop_back();

        }
    }
}

int main (){
    cin >> N;
    vector<int> a(N);
    vector<int> b;

    rep(i,0,N) {
        cin >> a[i];
    }

    dfs(a,b);
    cout << ans << endl;
}



