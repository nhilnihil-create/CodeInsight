#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;
using Graph = Vvec<int>;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main()
{
    int N, M;
    string s;
    cin >> N >> M >> s;
    Graph graph(N);
    for(int i=0; i<M; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> A(N), B(N);
    for(int i=0; i<N; i++){
        if(s[i] == 'A'){
            for(auto j: graph[i]) A[j]++;
        }else{
            for(auto j: graph[i]) B[j]++;
        }
    }

    // debug(A);
    // debug(B);
    queue<int> q;
    set<int> st;
    for(int i=0; i<N; i++){
        if(A[i] == 0 || B[i] == 0) q.push(i);
        else st.insert(i);
    }

    while(!q.empty()){
        int i = q.front();
        q.pop();
        if(s[i] == 'A'){
            for(auto j: graph[i]){
                if(st.find(j) == st.end()) continue;
                A[j]--;
                if(A[j] == 0){
                    st.erase(j);
                    q.push(j);
                }
            }
        }else{
            for(auto j: graph[i]){
                if(st.find(j) == st.end()) continue;
                B[j]--;
                if(B[j] == 0){
                    st.erase(j);
                    q.push(j);
                }
            }
        }
    }

    cout << ((st.empty()) ? "No" : "Yes") << "\n";
    // cout << st.size() << endl;
}