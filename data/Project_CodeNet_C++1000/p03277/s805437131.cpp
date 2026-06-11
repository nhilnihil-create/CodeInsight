#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using P=pair<int,int>;
using lint=long long;
using ll=long long;
const lint inf=1e18+7;
const int MOD=1000000007;
class Seg_Tree{
    private:
    int e=1000000007;
    int n;
    vector<int> node;
    public:
    int process(int left,int right){
        if(left==e)return right;
        if(right==e)return left;
        return left+right;
    }
    Seg_Tree(vector<int> v){
        int num=1;
        int size=v.size();
        while(num<size){
            num*=2;
        }
        n=num;
        node.resize(2*num-1,e);
        for(int i=0;i<size;i++)node[i+num-1]=v[i];
        for(int i=n-2;i>=0;i--)node[i]=process(node[i*2+1],node[i*2+2]);
    }
    void update(int x,int val){
        x+=(n-1);
        node[x]+=val;
        while(x>0){
            x=(x-1)/2;
            node[x]=process(node[x*2+1],node[x*2+2]);
        }
    }
    int out(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        if(a>=r||b<=l)return e;
        if(a<=l&&b>=r)return node[k];
        int vl=out(a,b,k*2+1,l,(l+r)/2);
        int vr=out(a,b,k*2+2,(l+r)/2,r);
        return process(vl,vr);
    }
};
bool judge(vector<int> const& a,int key){
  int n=a.size()-1;
  vector<int> sum(n+1,0);
  //cout<<"key="<<key<<endl;
  rep1(i,n){
    sum[i]=sum[i-1];
    if(a[i]>key){
      sum[i]++;
      //cout<<"u"<<" ";
    }
    else{
      sum[i]--;
      //cout<<"d"<<" ";
    }
  }
  int buf=0;
  Seg_Tree tree(vector<int> (2*n+5,0));
  rep(i,n+1){
    buf+=tree.out(0,sum[i]+n+1);
    tree.update(sum[i]+n,1);
    //printf("i=%lld, buf=%lld\n",i,buf);
  }
  //cout<<endl;
  //printf("buf=%lld\n",buf);
  int num=((n+1)*n)/2;
  if(buf>=(num+1)/2){
    return true;
  }
  else{
    return false;
  }
}
signed main(){
  int n;cin>>n;
  vector<int> a(n+1,0);
  rep1(i,n)cin>>a[i];
  int d=0;
  int u=inf;
  while(u-d>1){
    int mid=(u+d)/2;
    if(judge(a,mid)){
      d=mid;
    }
    else u=mid;
  }
  sort(a.begin(),a.end());
  auto it=upper_bound(ALL(a),d);
  cout<<*it<<"\n";
  return 0;
}
