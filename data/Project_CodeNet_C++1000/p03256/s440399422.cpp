#include <bits/stdc++.h>
using namespace std;

int N, M;
string S;
const int MAX = 200000;
vector<int> edges[MAX];
int numA[MAX], numB[MAX];
bool deleted[MAX];

void del(int i){
    if(deleted[i]) return;
    deleted[i] = true;
    for(auto j : edges[i]){
        if(deleted[j]) continue;
        (S[i] == 'A' ? numA[j] : numB[j]) -= 1;
        if(numA[j] == 0 || numB[j] == 0) del(j);
    }
}

int main(){
    int i, j, k;
    cin >> N >> M >> S;
    for(i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
        (S[b] == 'A' ? numA[a] : numB[a]) += 1;
        (S[a] == 'A' ? numA[b] : numB[b]) += 1;
    }

    for(i=0; i<N; i++){
        if(numA[i] == 0 || numB[i] == 0) del(i);
    }
    for(i=0; i<N; i++){
        if(!deleted[i]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}