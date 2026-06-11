#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> P;

int n,a[(1<<18)];
P p[(1<<18)];

P g(P x, P y){
    set<P> s;
    s.insert(P(-a[x.first], x.first));
    s.insert(P(-a[x.second], x.second));
    s.insert(P(-a[y.first], y.first));
    s.insert(P(-a[y.second], y.second));
    auto itr=s.begin();
    P r=P(0, 0);
    r.first=(*itr).second;
    itr++;
    r.second=(*itr).second;
    return r;
}

P f(int x){
    if(p[x].first>=0)return p[x];
    int b=0;
    for(int i=0;i<n;i++){
        if(((x>>i)&1)==1){
            b++;
        }
    }
    if(b==0)return P(0, 0);
    if(b==1)return P(x, 0);
    P r=P(x, 0);
    for(int i=0;i<n;i++){
        if(((x>>i)&1)==1){
            P t=f(x-(1<<i));
            r=g(r, t);
        }
    }
    return p[x]=r;
}
int main(void){
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        cin>>a[i];
        p[i]=P(-1, 0);
    }
    int z=0;
    for(int i=1;i<(1<<n);i++){
        P q=f(i);
        //cout << i << " : " << q.first << ", " << q.second << endl;
        int x=a[q.first]+a[q.second];
        z=max(z, x);
        cout << z << endl;
    }
}
