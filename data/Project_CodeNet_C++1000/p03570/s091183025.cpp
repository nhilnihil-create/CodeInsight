#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> edges[210000];

int main(){
    string str;
    cin >> str;
    int cur = 0;

    map<int,int> dist;

    dist[0] = 0;
    for(int i = 0; i < str.size(); i++){
        int a = str[i] - 'a';
        cur ^= (1 << a);

        if(dist.find(cur) == dist.end()){
            dist[cur] = 1e7;
        }
        for(int j = 0; j < 26; j++){
            int c = cur ^ (1<<j);
            if(dist.find(c) == dist.end()) continue;
            dist[cur] = min(dist[cur], dist[c] + 1);
        }
    }
    cout << max(dist[cur], 1) << endl;
}
