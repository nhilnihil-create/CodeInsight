#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
#define NIL -1
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<char>>;
using P =pair<int,int>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
const ll mod=1000000007;

int main(){
    string s;
    cin>>s;
    int l=s.size();
    int ans=753;
    rep(i,l-2){
        int x=(s[i]-'0')*100;
        x+=(s[i+1]-'0')*10;
        x+=(s[i+2]-'0')*1;
        int a=abs(x-753);
        ans=min(ans,a);
    }
    cout<<ans<<endl;
}

