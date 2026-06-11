#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n,k,q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int ans=IINF;
  for(int i=0;i<n;i++){
    priority_queue<int,vector<int>,function<bool(int,int)>>
      thp([](const int &a, const int &b){return a>b;});
    priority_queue<int,vector<int>,function<bool(int,int)>>
      heap([](const int &a, const int &b){return a>b;});
    for(int j=0;j<n;j++){
      if(a[j]>=a[i]){
        heap.push(a[j]);
      }else{
        while(heap.size()>=k){
          thp.push(heap.top());
          heap.pop();
        }
        while(!heap.empty()) heap.pop();
      }
    }
    while(heap.size()>=k){
      thp.push(heap.top());
      heap.pop();
    }
    int tmp;
    for(int k=0;k<q;k++){
      if(thp.empty()) goto next;
      tmp=thp.top();
      thp.pop();
    }
    tmp-=a[i];
    ans=min(ans,tmp);
    next:;
  }
  cout << ans << endl;
  return 0;
}