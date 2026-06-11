#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > v(n);
    vector<int> a(m);
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;

        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }

    int ans = 0;
    for(int i = 0; i < m; i++){
        if(v[a[i]].size() == 1 || v[b[i]].size() == 1){
            ans++;
        }else{
            queue<int> q;
            int flag[n];
            int che = 0;
            for(int j = 0; j < n; j++){
                flag[j] = 0;
            }
            if(v[a[i]].size() < v[b[i]].size()){
                for(int j = 0; j < v[a[i]].size(); j++){
                    if(v[a[i]][j] != b[i]){
                        q.push(v[a[i]][j]);
                        flag[v[a[i]][j]] = 1;
                    }
                }

                flag[a[i]] = 1;

                while(!q.empty()){
                    int k = q.front();
                    q.pop();

                    if(k == b[i]){
                        che = 1;
                        break;
                    }

                    for(int j = 0; j < v[k].size(); j++){
                        if(flag[v[k][j]] == 0){
                            q.push(v[k][j]);
                            flag[v[k][j]] = 1;
                        }
                    }
                }

                if(che == 0){
                    ans++;
                }
            }else{
                for(int j = 0; j < v[b[i]].size(); j++){
                    if(v[b[i]][j] != a[i]){
                        q.push(v[b[i]][j]);
                        flag[v[b[i]][j]] = 1;
                    }
                }

                flag[b[i]] = 1;

                while(!q.empty()){
                    int k = q.front();
                    q.pop();

                    if(k == a[i]){
                        che = 1;
                        break;
                    }

                    for(int j = 0; j < v[k].size(); j++){
                        if(flag[v[k][j]] == 0){
                            q.push(v[k][j]);
                            flag[v[k][j]] = 1;
                        }
                    }
                }

                if(che == 0){
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}