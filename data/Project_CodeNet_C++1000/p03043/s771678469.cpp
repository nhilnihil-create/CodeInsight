#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int main(){
    int n,k;
    cin>>n>>k;
    double ans=0;
    rep(i,n){
        int p=i+1;
        int n=0;
        while(p*pow(2,n)<k){
            ++n;
        }
        ans+=pow(0.5,n);
    }
    cout<<fixed<<setprecision(9)<<ans/n<<endl;
}

        
