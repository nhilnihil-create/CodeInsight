#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    int tmp = 0;
    priority_queue<int,vector<int>,greater<int> > pq;
    int ans = 0,top,size;
    int l,r;

    rep(i,100){
        rep(j,100){
            if(i+j > min(n,k))break;

            tmp = 0;
            pq =  priority_queue<int,vector<int>,greater<int> >();
            l = i,r = j;

            rep(a,min(i,n)){
                pq.push(v[a]);
            }

            rep(b,min(j,n-i)){
                pq.push(v[n-1-b]);
            }

            rep(l,k-min(i,n)-min(j,n-i) ){
                if(pq.empty()) break;
                top = pq.top();
                if(top < 0) pq.pop();
                else break;
            }
            
            size = pq.size();
            rep(l,size){
                tmp += pq.top();
                pq.pop();
            }
            ans = max(ans,tmp);
        }
    }

    cout << ans << endl;
    return 0;
}