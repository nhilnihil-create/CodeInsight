#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

vector<int> X;
int ans;
int D[13];

void calc(){
    int tmp = 24;
    int size = X.size();
    REP(i,size){
        int x = X[i];
        REPi(j,i+1,size){
            int y = X[j];
            int diff = abs(x-y);
            chmin(tmp, min(diff, 24-diff));
        }
    }
    chmax(ans, tmp);
}

void dfs(int idx){
    if(idx == 13){
        calc();
        return;
    }

    int d = D[idx];
    if(idx == 0 || idx == 12){
        if(d == 0)
            dfs(idx+1);
        else if(d == 1){
            X.push_back(idx);
            dfs(idx+1);
            X.pop_back();
        }
        else if(d == 2){
            X.push_back(idx);
            X.push_back(idx);
            dfs(idx+1);
            X.pop_back();
            X.pop_back();
        }
    }
    else{
        if(d == 0)
            dfs(idx+1);
        else if(d == 1){
            X.push_back(idx);
            dfs(idx+1);
            X.pop_back();

            X.push_back(24-idx);
            dfs(idx+1);
            X.pop_back();
        }
        else if(d == 2){
            X.push_back(idx);
            X.push_back(24-idx);
            dfs(idx+1);
            X.pop_back();
            X.pop_back();
        }
    }
}

int main(){
    int N;
    cin >> N;
    bool zero = false;
    D[0]++;
    REP(i,N){
        int d;
        cin >> d;
        D[d]++;
        if(D[d] == 3){
            zero = true;
        }
    }

    if(zero){
        cout << 0 << endl;
        return 0;
    }

    ans = 0;
    dfs(0);

    cout << ans << endl;
    return 0;
}
