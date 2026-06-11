#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define repn(i, n) for(int i = 1; i <= n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define lint long long

const int MAX_V = 205;

int V;
vector<int> to[MAX_V];
int match[MAX_V];
bool used[MAX_V];

bool dfs(int x){
    used[x] = true;
    for(auto& y : to[x]){
        int z = match[y];
        if(z < 0 || (!used[z] && dfs(z))){
            match[x] = y;
            match[y] = x;
            return true;
        }
    }
    return false;
}

int largest_matching(){
    int res = 0;
    memset(match, -1, sizeof(match));
    for(int v = 0; v < V; v++){
        if (match[v] < 0){
            memset(used, false, sizeof(used));
            if(dfs(v)) res++;
        }
    }
    return res;
}

void display_matching(){
    rep(v, V){
        if(match[match[v]] == v){
            cout << "M: " << v << " & " << match[v] << endl;
        }
    }
}

int main(){
    int n; cin >> n;
    V = n * 2;

    vector<pair<int, int> > red, blue;
    rep(i, n){
        int a, b; cin >> a >> b;
        red.push_back(make_pair(a, b));
    }
    rep(i, n){
        int a, b; cin >> a >> b;
        blue.push_back(make_pair(a, b));
    }

    rep(i, n) rep(j, n){
        if(red[i].first < blue[j].first && red[i].second < blue[j].second){
            to[i].push_back(j + n);
            to[j + n].push_back(i);
        }
    }

    int res = largest_matching();
    cout << res << endl;
}