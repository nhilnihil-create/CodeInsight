#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int s,e,m,v,la;
    node  *l, *r;
    node (int _s, int _e): s(_s), e(_e){
        m = (s+e)/2;
        la = 0;
        if (s == e){
            if (s == 0) v =0;
            else v = -1;
        }
        else{
            l = new node(s,m);
            r = new node(m+1,e);
            v = l->v + r->v;
        }
    }
    void prop(){
        if (la){
            v = 0;
            if (s != e ){
                l -> la = 1;
                r -> la = 1;
            }
            la = 0;
        }
    }
    void up(int qs, int qe){
        prop();
        if (qs == s && qe == e){
            la = 1;
            return;
        }
        if (qs  > m) r->up(qs,qe);
        else if (qe <= m)  l->up(qs,qe);
        else l->up(qs,m), r->up(m+1,qe);
        l->prop(); r->prop();
        v = l->v+r->v;
    }
    int qu(int qs, int qe){
        prop();
        if (qs == s && qe == e)  return v;
        if (qs > m) return r->qu(qs,qe);
        else if (qe <= m) return l->qu(qs,qe);
        else return l->qu(qs,m) + r->qu(m+1,qe);
    }
} *root;
int n;
int a[200005];

int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        //a[i] = min(i,n/2);
        scanf("%d",&a[i]);
    }
    root = new node(0,n-1);
    ll ans = 0;
    for (int i = n-1; i >=0; i--){
        int expect = i+root->qu(0,i);
        //printf("%d: %d %d\n",i,expect,a[i]);
        if (expect != a[i]){
            ans += a[i];
            root->up(min(i,max(0,i-a[i]+1)),i);
            if (i+root->qu(0,i) != a[i]){
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%lld",ans);
}
