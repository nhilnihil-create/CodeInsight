#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n, m; cin >> n >> m;
    priority_queue<int, vector<int>, greater<int> > que; 
    for(int i=0; i<n; ++i){int a; cin >> a; que.push(a);}
    vector<pair<int, int>> p(m); 
    for(int i=0; i<m; ++i){
        int b, c; cin >> b >> c;
        p[i] = make_pair(c, b);
    }
    sort(p.begin(), p.end()); 
    for(int i=0; i<m; ++i){
        int c = p[m-i-1].first, b = p[m-i-1].second;//cout << que.size() << endl;
        if(que.top()>=c){break;}
        for(int i=0; i<b; ++i){
            if(que.top()<c){ //cout << que.top() << endl;
                que.pop(); que.push(c); 
            }else{break;}
        }
    }
    ll res = 0; //cout << que.size() << endl;
    while(!que.empty()){
        res += que.top(); //cout << "top:" << que.top() << endl; 
      	que.pop(); //cout << "size:" << que.size() << endl; cout << "atop:" << que.top() << endl;
    }
    cout << res << endl; 
    return 0;
}