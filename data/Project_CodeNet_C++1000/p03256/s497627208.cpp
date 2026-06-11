#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int n, m;
string s;
int field[200100];
vector<int> children[200010];
bool ok[200100];

void search(int from){
    bool checker[2];
    checker[0] = false;
    checker[1] = false;
    for(int i = 0; i < children[from].size(); i++){
        int to = children[from][i];
        if(!ok[to]){
            continue;
        }
        checker[field[to]] = true;
        if(checker[0] && checker[1]){
            return;
        }
    } 
    ok[from] = false;
}
void search2(int from){
    if(!ok[from]) return;
    bool checker[2];
    checker[0] = false;
    checker[1] = false;
    for(int i = 0; i < children[from].size(); i++){
        int to = children[from][i];
        if(!ok[to]){
            continue;
        }
        checker[field[to]] = true;
        if(checker[0] && checker[1]){
            return;
        }
    } 
    ok[from] = false;
    for(int i = 0; i < children[from].size(); i++){
        if(ok[children[from][i]]) search2(children[from][i]);
    }
    return;
}

int main() {
    //cout.precision(10);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == 'A'){
            field[i] = 0;
        } else {
            field[i] = 1;
        }
    }
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        if(a == b){
            children[a].push_back(b);
            continue;
        }
        children[a].push_back(b);
        children[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        ok[i] = true;
    }
    for(int time = 1; time <= 100; time++){
        for(int i = 1; i <= n; i++){
            if(ok[i]) search(i);
        }
    }
    for(int i = 1; i <= n; i++){
        search2(i);
    }
    for(int i = 1; i <= n; i++){
        if(ok[i]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
