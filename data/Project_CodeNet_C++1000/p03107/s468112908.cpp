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

const double PI=(acos(-1));

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int cnt0=0,cnt1=0;
    rep(i,n){
        if(s[i]=='1')++cnt1;
        else ++cnt0;
    }
    int diff=abs(cnt1-cnt0);
    cout<<n-diff<<endl;
}