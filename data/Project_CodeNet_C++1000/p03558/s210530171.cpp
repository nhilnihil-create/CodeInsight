#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define x first
#define y second
int k;
bool visited[1000001];

int main(){
    cin >> k;
    deque<ii> q;
    q.push_back(ii(1, 1));
    while(!q.empty()){
        ii u = q.front(); q.pop_front();
        if (visited[u.x]) continue;
        visited[u.x] = true;
        if (u.x == 0){
            cout << u.y;
            break;
        }
        else{
            q.push_front(ii(u.x*10%k, u.y));
            q.push_back(ii((u.x + 1)%k, u.y + 1));
        }
    }
}