#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

using namespace std;

int main(){
    int N;  cin >> N;
    vector<int> v(N);
    priority_queue<int> q1, q2;
    rep(i,N)    cin >> v[i];
    int a1, a2, tmp, cnt, ans1, ans2;
    a1 = v[0];
    a2 = v[1];
    for(int i=1; i<=int(sqrt(a1)); i++){
        if(a1%i == 0){
            q1.push(i);
            if(a1%(a1/i)==0)    q1.push(a1/i);
        }
    }
    for(int i=1; i<=int(sqrt(a2)); i++){
        if(a2%i == 0){
            q2.push(i);
            if(a2%(a2/i)==0)    q2.push(a2/i);
        }
    }
    ans1 = 0;
    ans2 = 0;
    while(!q1.empty()){
        tmp = q1.top();
        q1.pop();
        cnt = 0;
        rep(i,N){
            if(v[i]%tmp != 0)   cnt++;
        }
        if(cnt <= 1){
            ans1 = tmp;
            break;
        }
    }
    while(!q2.empty()){
        tmp = q2.top();
        q2.pop();
        cnt = 0;
        rep(i,N){
            if(v[i]%tmp != 0)   cnt++;
        }
        if(cnt <= 1){
            ans2 = tmp;
            break;
        }
    }
    cout << max(ans1,ans2);
}