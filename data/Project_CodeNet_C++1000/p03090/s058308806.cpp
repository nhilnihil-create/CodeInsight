#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;
vector<int> graph[110];
int visited[110][110];
int edgecnt;
int main()
{
    int n;cin >> n;
    if(n%2){
        
        for(int i = 1;i < n-i;i++){
            graph[i].push_back(n-i);
            graph[n-i].push_back(i);
            visited[i][n-i] = 1;
            visited[n-i][i] = 1;
            edgecnt++;

        }
        cout << n*(n-1)/2 - edgecnt << endl;
        for(int i = 1;i <=n ;i++){
            for(int j = i+1;j <= n ;j++){
                
                if(!visited[i][j])printf("%d %d\n",i,j);
            }
        }

    }
    else{
        for(int i = 1;i < n-i+1;i++){
            graph[i].push_back(n-i+1);
            graph[i].push_back(n-i+1);
            visited[i][n-i+1] = 1;
            visited[n-i+1][i] = 1;
            edgecnt++;
        }
        cout << n*(n-1)/2 - edgecnt << endl;
        for(int i = 1;i <=n ; i++){
            for(int j = i+1;j <= n;j++){
                if(!visited[i][j])printf("%d %d\n",i,j);
            }
        }
    }
    return 0;
}