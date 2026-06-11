#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int N, M, L, R, D;
vector<pair<int, int> > adj[100000];

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> L >> R >> D;
        L--; R--;
        adj[L].push_back(make_pair(R, D));
        adj[R].push_back(make_pair(L, -D));
    }

    bool visited[100000] = {};
    int dist[100000] = {};
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            stack<int> st;
            st.push(i);
            dist[i] = 0;
            while(!st.empty()){
                int now = st.top(); st.pop();
                visited[now] = true;
                for(int j = 0; j < adj[now].size(); j++){
                    int next = adj[now][j].first;
                    int d = adj[now][j].second;
                    if(!visited[next]){
                        st.push(next);
                        dist[next] = dist[now]+d;
                    }else{
                        if(dist[next] != dist[now] + d){
                            cout << "No" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
}