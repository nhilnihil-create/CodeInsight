#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()

const vector<int> pr={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};


int main(){
    int n,ans=0;
    cin>>n;
    map<int,int> mp;
    for(int i=2; i<=n; ++i){
       for(auto&v :pr){
           int a=i;
           while(a%v==0){
               mp[v]++;
               a/=v;
           }
       }
    }
    vector<int> cn(2,0);
    for(auto&v: mp){
        if(v.second>1 && v.second<4) cn[0]++;
        else if(v.second>=4) cn[1]++; 
    }
    ans+=cn[0]*cn[1]*(cn[1]-1)/2;
    ans+=(cn[1]*(cn[1]-1)*(cn[1]-2))/2;
    //cout<<ans<<endl;
    cn[0]=0; cn[1]=0;
    for(auto&v :mp){
        if(v.second>=2){
            if(v.second>=24) cn[0]++;
            else cn[1]++;
        }
    }
    ans+=cn[0]*cn[1];
    ans+=cn[0]*(cn[0]-1);
    //cout<<ans<<endl;
    cn[0]=0; cn[1]=0;
    for(auto&v: mp){
        if(v.second>=4){
            if(v.second>=14) cn[1]++;
            else cn[0]++;
        }
    }
    ans+=cn[0]*cn[1];
    ans+=cn[1]*(cn[1]-1);
    //cout<<ans<<endl;
    cn[0]=0; cn[1]=0;
    for(auto&v : mp){
        if(v.second>=74) cn[0]++;
    }
    ans+=cn[0];
    cout<<ans<<endl;
    return 0;
}