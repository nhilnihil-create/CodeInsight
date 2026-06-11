#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    map<P, int> mp;
    int a[200005], b[200005];
    vector<int> v[200005];
    int na[200005] {0}, nb[200005] {0};
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        if(mp[P(a[i], b[i])]) continue;
        mp[P(a[i], b[i])] = 1;
        mp[P(b[i], a[i])] = 1;
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
        if(s[b[i]] == 'A') na[a[i]]++;
        else nb[a[i]]++;
        if(s[a[i]] == 'A') na[b[i]]++;
        else nb[b[i]]++;
    }
    bool f[200005];
    fill(f, f + n, true);
    for(int i = 0; i < n; i++){
        if(f[i] && (na[i] <= 0 || nb[i] <= 0)){
            queue<int> que;
            f[i] = false;
            que.push(i);
            while(que.size()){
                int now = que.front();
                que.pop();
                for(int next : v[now]){
                    if(!f[next]) continue;
                    if(s[now] == 'A') na[next]--;
                    else nb[next]--;
                    if(na[next] <= 0 || nb[next] <= 0){
                        f[next] = false;
                        que.push(next);
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(f[i]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
