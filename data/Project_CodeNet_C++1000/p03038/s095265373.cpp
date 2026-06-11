#include<bits/stdc++.h>
 
#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'
 
using namespace std;
 
const int N = 2e5 + 77;
priority_queue<int , vector<int> , greater<int>> A;
vector<pair<int,int>> P;
int32_t main(){
    fast;
    int n , m ; cin >> n >> m ;
    for(int i = 0; i < n ; ++i){
        int a ; cin >> a;
        A.push(a);
    }
    for(int q = 0; q < m ; ++q){
        int a , b; cin >> a >> b ;
        P.push_back({b,a});
    }
    sort(P.rbegin(),P.rend());
    for(auto i : P){
        int a = i.first , b = i.second;
        if(A.top() >= a) break;
        for(int j = 0 ; j < b ; ++j){
            A.pop();
            A.push(a);
        }
    }
 
    int ans = 0;
    while(!A.empty()){
        ans += A.top();
        A.pop();
    }
    cout << ans << endl;
    return 0;
}