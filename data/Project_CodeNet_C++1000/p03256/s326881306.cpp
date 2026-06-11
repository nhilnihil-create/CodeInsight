#include <iostream>
#include <vector>

using namespace std;

vector<int> G[200000];
int cnta[200000], cntb[200000];
bool deleted[200000];
string S;

void del(int v){
    deleted[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        if(S[v] == 'A'){
            cnta[G[v][i]]--;
            if(cnta[G[v][i]] == 0 && !deleted[G[v][i]]) del(G[v][i]);
        }else{
            cntb[G[v][i]]--;
            if(cntb[G[v][i]] == 0 && !deleted[G[v][i]]) del(G[v][i]);
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    cin >> S;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(a != b){
            G[a].push_back(b);
            G[b].push_back(a);
            if(S[a] == 'A'){
                cnta[b]++;
            }else{
                cntb[b]++;
            }
            if(S[b] == 'A'){
                cnta[a]++;
            }else{
                cntb[a]++;
            }
        }else{
            G[a].push_back(a);
            if(S[a] == 'A'){
                cnta[a]++;
            }else{
                cntb[a]++;
            }
        }
    }
    for(int i = 0; i < N; i++){
        if((cnta[i] == 0 || cntb[i] == 0) && !deleted[i]) del(i);
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(!deleted[i]) cnt++;
    }
    //cout << cnt << endl;
    if(cnt != 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}