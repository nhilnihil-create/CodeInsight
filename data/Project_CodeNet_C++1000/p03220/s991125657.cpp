#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define NIL -1
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using P =pair<int,int>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
const ll mod=1000000007;

int main(){
    int n;
    cin>>n;
    double t,a;
    cin>>t>>a;
    int ans=0;
    double diff=10000;
    rep(i,n){
        double h;
        cin>>h;
        double temp=abs(a-(t-h*0.006));
        if(diff>temp){
            diff=temp;
            ans=i+1;
        }
    }
    cout<<ans<<endl;
}
        

