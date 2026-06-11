#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;


struct Node{
    vector<ll> path;
    vector<ll> weight;
    ll color;
};

ll putColor(Node T[], ll id, ll color){
    T[id].color = color;
    for(ll i = 0; i < T[id].path.size(); i++){
        ll next = T[id].path[i];
        if(T[next].color == 0){
            if(T[id].weight[i] % 2 == 0){
                putColor(T, next, color);
            }else{
                putColor(T, next, color * -1);
            }
        }
    }

    return 0;
}

int main(){
    int N;

    cin >> N;

    Node T[N + 1];

    for(ll i = 1; i < N; i++){
        ll u, v, w;
        cin >> u >> v >> w;

        T[u].path.push_back(v);
        T[u].weight.push_back(w);
        T[u].color = 0;
        T[v].path.push_back(u);
        T[v].weight.push_back(w);
        T[v].color = 0;
    }

    putColor(T, 1, 1);

    for(ll i = 1; i < N + 1; i++){
        if(T[i].color == 1){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }

    return 0;
}
