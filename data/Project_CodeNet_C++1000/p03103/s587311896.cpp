#include<bits/stdc++.h>
using namespace std;
typedef pair<int64_t ,int64_t> P;

int main(){
    int n,m;
    cin >> n >> m;

    priority_queue<P ,vector<P> ,greater<P>> que;

    for(int i=0;i<n;i++){
        int64_t a,b;
        cin >> a >> b;
        que.push(P (a ,b));
    }

    int64_t sumc = 0 ,sumn = 0;

    while(true){
        P p = que.top(); que.pop();
        int64_t cost = p.first;
        int64_t num = p.second;
        if(sumn + num >= m){
            sumc += (m - sumn)*cost;
            break;
        }

        sumc += cost * num;
        sumn += num;
    }

    cout << sumc << endl;
}