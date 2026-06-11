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
    int n;
    cin>>n;
    vector<tuple<string,int,int>> a;
    for(int i=1;i<=n;++i){
        string s;
        int p;
        cin>>s>>p;
        p=-p;
        a.push_back(tie(s,p,i));
    }
    sort(a.begin(),a.end());
    rep(i,n){
        cout<<get<2>(a[i])<<endl;
    }
}

