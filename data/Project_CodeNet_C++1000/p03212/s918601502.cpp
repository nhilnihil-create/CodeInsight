#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int ans = 0;
int l;
int N;
void dfs(vector<int> &A) {
    if (A.size()==l) {
        int tmp = 0;
        bool t = false;
        bool h = false;
        bool t3,t5,t7;
        t3 = t5 = t7 = false;
        rep(i,A.size()) {
            if (t&&A[i]==0) h = true;
            if (A[i]>0) t = true;
            if (A[i]==3) t3 = true;
            if (A[i]==5) t5 = true;
            if (A[i]==7) t7 = true;
            tmp = tmp*10+A[i];

        }
        if (h || tmp>N) return;
        else if (t3 && t5 && t7) ans++;
        return;
    }
    else {
        int d[4] = {0,3,5,7};
        rep(i,4) {
            A.push_back(d[i]);
            dfs(A);
            A.pop_back();
        }
    }
    return;
}


int main(){
    cin >> N;
    int t = N;
    while(t>10) {
        t/=10;
        l++;
    }
    l++;
    vector<int> A;
    dfs(A);
    cout << ans << endl;
}
