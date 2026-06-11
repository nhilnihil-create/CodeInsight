#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<vector<P>> T(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b, w;
        cin >> a >> b >> w;
        T[a].push_back(make_pair(b, w));
        T[b].push_back(make_pair(a, w));
    }

    vector<int> color(n+1);
    vector<bool> isvisit(n+1, false);
    queue<int> Q;
    Q.push(1);
    isvisit[1] = true;
    color[1] = 0;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int i = 0; i < T[cur].size(); i++){
            if(!isvisit[T[cur][i].first]){
                isvisit[T[cur][i].first] = true;
                if(T[cur][i].second % 2 == 0){
                    color[T[cur][i].first] = color[cur];
                }else{
                    color[T[cur][i].first] = (color[cur]+1)%2;
                }
                Q.push(T[cur][i].first);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << color[i] << endl;
    }
    return 0;
}