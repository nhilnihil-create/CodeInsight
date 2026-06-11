#include<iostream>
#include<vector>
using namespace std;

vector<int> G[100001];

bool bipa;
bool visited[100001];
int col[100001];

void dfs(int v){
    int i;
    if(bipa){
        for(i=0; i<G[v].size(); i++){
            if(bipa){
                if(visited[G[v][i]]==0){
                    visited[G[v][i]]=1;
                    col[G[v][i]]=(!col[v]);
                    dfs(G[v][i]);
                }else{
                    if(col[G[v][i]]==col[v]){
                        bipa=0;
                    }
                }
            }
        }
    }
}

int main(){
    //input
    long long N,M;
    cin >> N >> M;
    int A,B;
    int i;
    for(i=0; i<M; i++){
        cin >> A >> B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    //calc
    bipa=1;
    visited[1]=1;
    col[1]=1;
    dfs(1);
    long long ans;
    if(bipa){
        long long odd=0, even=0;
        for(i=1; i<=N; i++){
            if(col[i]==1){
                odd++;
            }else{
                even++;
            }
        }
        ans=odd*even-M;
    }else{
        ans=(N*(N-1))/2-M;
    }

    //output
    cout << ans << endl;
    system("pause");
    return 0;
}