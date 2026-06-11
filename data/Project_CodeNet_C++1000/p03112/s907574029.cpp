#include <bits/stdc++.h>
using namespace std;

int64_t G=167167167167;
int64_t H=G*-1;


int main() {
  int A,B,Q;
  cin>>A>>B>>Q;
  vector<int64_t> p(A+2);
  vector<int64_t> q(B+2);
  for(int i=1;i<=A;i++){
    cin>>p[i];
  }
  for(int i=1;i<=B;i++){
    cin>>q[i];
  }
  p[0]=H;
  q[0]=H;
  p[A+1]=G;
  q[B+1]=G;
  for(int i=0;i<Q;i++){
    int64_t N;
    cin>>N;
    int64_t LP,LQ,RP,RQ;
    int a,b;
    a=lower_bound(p.begin(),p.end(),N)-p.begin();
    b=lower_bound(q.begin(),q.end(),N)-q.begin();
    LP=N-p[a-1];
    RP=p[a]-N;
    LQ=N-q[b-1];
    RQ=q[b]-N;
    int64_t Z=min(min(max(LP,LQ),max(RP,RQ)),min(min(LP,RQ)*2+max(LP,RQ),min(RP,LQ)*2+max(RP,LQ)));
    cout<<Z<<endl;
  }
}