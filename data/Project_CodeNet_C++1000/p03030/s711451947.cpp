#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!


struct Node{
public:
    string name;
    int p;
    int idx;
    Node(){
        name="";
        p=0;
        idx=0;
    }
    Node(string name,int p,int idx){
        this->p=p;
        this->name=name;
        this->idx=idx;
    }
};
class Comp{
public:
    bool operator()(const Node &a,const Node &b){
        return a.name!=b.name ? a.name<b.name : a.p > b.p;    
    }
};
void solve(){
    int n;
    cin>>n;
    vector<Node> arr;
    for(int i=0;i<n;++i){
        string name;
        int p;
        cin>>name>>p;
        arr.pb(Node(name,p,i+1));
    }
    sort(all(arr),Comp());
    for(int i=0;i<n;i++){
        cout<<arr[i].idx<<endl;
    }
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