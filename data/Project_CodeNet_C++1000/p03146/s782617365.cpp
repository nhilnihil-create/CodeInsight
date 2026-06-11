#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define NIL -1
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

const double PI=(acos(-1));

int main(){
    int s;
    cin>>s;
    vector<int> m(1000001);
    int a=s,ans=1;
    while(1){
        if(m[a]!=0)break;
        m[a]++;
        ans++;
        if(a%2==0){
            a/=2;
        }else{
            a=3*a+1;
        }
    }
    cout<<ans<<endl;
}