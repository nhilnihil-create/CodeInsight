#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <string.h>

using namespace std;
const int maxn = 2e5+1 ;
vector<int> arr[maxn] ;
int len[maxn] ;
int n ;
int bfs(int x){
    memset(len,0,sizeof(len)) ;
    len[x] = 1 ;
    queue<int> q ;
    q.push(x) ;
    int z = 1 ;
    int flog = 1 ;
    while(!q.empty()) {
        int y = q.front() ;
        q.pop() ;
        for (int i = 0 ; i < arr[y].size() ;  i++ ) {
            z = arr[y][i] ;
            if (!len[z]){
                len[z] = len[y]+1 ;
                flog++ ;
                q.push(z) ;
            }
            if (flog == n) return z ;
        }
        if (flog == n) return z ;
    }
    if (flog == n) return z ;
}

int main()
{
    cin >> n ;
    for (int i = 1 ; i < n ; i++) {
        int a , b ;
        cin >> a >> b ;
        arr[a].push_back(b) ;
        arr[b].push_back(a) ;
    }
    int temp = bfs(1) ;
    int ans = bfs(temp) ;
    if (len[ans]%3==2) cout << "Second" << endl ;
    else cout << "First" << endl ;
    return 0;
}
