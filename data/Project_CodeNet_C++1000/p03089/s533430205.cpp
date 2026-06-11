#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    vector<int> B(N);
    rep(n,0,N) cin>>B.at(n);

    list<int> l;
    rep(n,0,N) l.push_back(B.at(n));

    vector<int> ans;
    while(!l.empty()){
        int minN,minD=INT_MAX;
        auto itr=l.begin();
        for(auto i=l.begin(); i!=l.end(); i++){
            int idx=distance(l.begin(),i)+1;
            if(idx<*i){cout<<-1<<endl; exit(0);}
            else{
                if(minD>=idx-*i){minD=idx-*i; minN=*i; itr=i;}
            }
        }
        l.erase(itr);
        ans.push_back(minN);
    }
    
    reverse(ToEnd(ans));
    for(auto a:ans) cout<<a<<endl;
}