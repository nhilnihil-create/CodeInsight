#include<bits/stdc++.h>
using namespace std;
int main(){
int A,B,Q;
  cin>>A>>B>>Q;
  vector<int64_t>s(A+2);
  s.at(0)=-10000000010;
  for(int i=1;i<=A;i++)
    cin>>s.at(i);
  s.at(A+1)=20000000010;
  vector<int64_t>t(B+2);
  t.at(0)=-10000000010;
  for(int i=1;i<=B;i++)
    cin>>t.at(i);
  t.at(B+1)=20000000010;
  for(int i=0;i<Q;i++){
  int64_t x;
    cin>>x;
    auto itr=lower_bound(s.begin(),s.end(),x);
    int k=distance(s.begin(),itr);
    int64_t S1=s.at(k)-x;
    int64_t S2=s.at(k-1)-x;
     auto itr1=lower_bound(t.begin(),t.end(),x);
    int l=distance(t.begin(),itr1);
    int64_t T1=t.at(l)-x;
    int64_t T2=t.at(l-1)-x;
      int64_t a=S1+min(abs(T2-S1),abs(T1-S1));
    int64_t b=abs(S2)+min(abs(T2-S2),abs(T1-S2));
    int64_t c=T1+min(abs(T1-S1),abs(T1-S2));
    int64_t d=abs(T2)+min(abs(T2-S1),abs(T2-S2));
    int64_t ans=min(min(a,b),min(c,d));
    cout<<ans<<endl;
      
  
  }
    return 0;
}
