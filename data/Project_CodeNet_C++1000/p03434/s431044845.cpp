#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()0
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=100009;
 
// Happy Coding!


void solve(){
    int n;
    cin>>n;
    priority_queue<int> pq;
    while(n-->0){
        int x;
        cin>>x;
        pq.push(x);
    }
    int sum=0;
    int p=0;
    while(!pq.empty()){
        if(!p){
            sum+=pq.top();
        }
        else{
            sum-=pq.top();
        }
        pq.pop();
        p=!p;
    }
    cout<<sum<<endl;
}

 
int main() {
    faster;
    int t=1;
    // cin>>t;
    
    while(t-->0){
        solve();
    }
	return 0;
}