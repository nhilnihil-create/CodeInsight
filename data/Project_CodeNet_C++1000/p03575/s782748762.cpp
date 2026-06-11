#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll lcm(ll x, ll y) {
    return x / GCD(x, y) * y;//先に割り算をして掛けられる数を小さくして掛け算を行う
}


int G[100][100];
bool seen[100];
int N, M;

void dfs(int v) {
    seen[v] = true;

    for (int i = 0; i < N; i++)
    {
        if (seen[i] == false && G[v][i] == true)
        {
            dfs(i);
        }
   
    }
}
int main() {
    int ans = 0;
    cin >> N >> M;
    vector<int> a(M), b(M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            G[i][j] = false;
        }
        
    }
    
    for (int i = 0; i < M; i++)
    {
       
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        G[a[i]][b[i]] = true;
        G[b[i]][a[i]] = true;
    
    }
    
    for (int i = 0; i < M; i++)
    {
        for (int h = 0; h < N; h++)
        {
           seen[h] = false;
        }
        
        G[a[i]][b[i]] = false;
        G[b[i]][a[i]] = false;
        dfs(0);
        bool result = true;
        for (int j = 0; j < N; j++)
        {
            if (!seen[j])
            {
                result = false;
            }
            
        }
        if (!result)
        {
            ans++;
        }
        G[a[i]][b[i]] = true;
        G[b[i]][a[i]] = true;
    }
    
    cout << ans << endl;


    
    return 0;
}