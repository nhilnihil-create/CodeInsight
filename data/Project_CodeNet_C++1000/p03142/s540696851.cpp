#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;
using ll = long long int;
const int MOD = 1e9 + 7;

int main(){
    int n, m; cin >> n >> m;
    vector<unordered_set<int>> vec(n);
    vector<int> in(n, 0);
    for(int i=0; i<n-1+m; i++){
        int a, b; cin >> a >> b; a--; b--;
        vec[a].insert(b);
        in[b]++;
    }
    vector<int> parent(n, -1);
    stack<int> st;
    for(int i=0; i<n; i++){
        if(in[i] == 0){st.push(i);}
    }
    while(!st.empty()){
        int i = st.top(); st.pop();
        for(auto& v:vec[i]){
            parent[v] = i;
            in[v]--;
            if(in[v] == 0){st.push(v);}
        }
    }
    for(auto& v:parent){
        cout << v + 1 << endl;
    }
    return 0;
}