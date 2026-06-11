#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<int>;
using vv = vector<v>;

int main(){
    int n;
    cin >> n;
    
    queue<ll> q;
    
    vector<int> a={3,5,7};
    
    q.push(3);
    q.push(5);
    q.push(7);
    
    int ans = 0;
    
    while(q.front()<=n){
        
        v c(3,0);
        ll k = q.front();
        while(k){
            if(k%10==3)c[0]++;
            if(k%10==5)c[1]++;
            if(k%10==7)c[2]++;
            k /=10;
        }
        if(c[0]&&c[1]&&c[2])
            ans++;
        for(auto b : a){
            q.push(q.front()*10+b);
        }
        q.pop();
    }
    cout << ans << endl;
    
    return 0;
}