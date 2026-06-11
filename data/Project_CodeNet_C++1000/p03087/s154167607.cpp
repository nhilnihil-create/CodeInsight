#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define DEBUG 0 
#define LIMIT (LONG_MAX / 10)
#define POSITIVE_LAST_D (LONG_MAX % 10)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;

int main(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> l(q),r(q);
    rep(i,q){
        cin>>l[i]>>r[i];
        --l[i];
        --r[i];
    }
    vector<int> ac(n,0);
    rep(i,n-1){
        if(s[i]=='A'&&s[i+1]=='C')ac[i]=1;
    }
    vector<int> csum(n,0);
    rep(i,n-1){
        csum[i+1]=csum[i]+ac[i];
    }
    rep(i,q){
        cout<<csum[r[i]]-csum[l[i]]<<endl;
    }

}