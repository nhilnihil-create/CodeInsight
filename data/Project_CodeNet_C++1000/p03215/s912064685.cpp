#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
int a[maxn];

vector<int> bit[64]; //idx
inline void divide(ll x,int idx){
    bitset<64> bb(x); //
    for(unsigned int i=0;i<64;i++){
   // cout<<bb[i];
        if(bb[i]) bit[i].push_back(idx);
    }
  //  cout<<endl;
}
vector<int> st;
bitset<64> ans;
inline void Union(vector<int> a,vector<int> b,vector<int>& c){
    set<int> ms;
    for(auto& it:a) ms.insert(it);
    for(auto& it:b) if(ms.count(it)) c.push_back(it);
}
int main(){
  //  divide(12,0);divide(14,0);
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    int idx=0;
    for(int i=1;i<=n;i++){
        ll sum=0;
        for(int j=i;j<=n;j++){
            sum+=a[j];
           // cout<<sum<<" ";
            divide(sum,++idx);
        }
    }

    int i;
    for(i=60;i>=0;i--){
        if(bit[i].size()>=k){
            for(auto& it:bit[i]){
                st.push_back(it);
            }
            ans[i]=1;
            break;
        }
    }
   // cout<<i<<endl;
    --i;
    for(;i>=0;i--){
   //     if(bit[i].size()<k) continue;
        vector<int> tmp;
        Union(st,bit[i],tmp);
        if(tmp.size()>=k){
            st=tmp;
            ans[i]=1;
        }
    }
    cout<<ans.to_ullong()<<endl;
}
