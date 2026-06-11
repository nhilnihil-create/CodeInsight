#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
int main(){
    int x,y,z,k;
    cin>>x>>y>>z>>k;
    vector<int64_t> A(x),B(y),C(z);
    map<tuple<int,int,int>,int> p;
    rep(i,x) cin>>A[i];
    rep(i,y) cin>>B[i];
    rep(i,z) cin>>C[i];
    all(A),all(B),all(C);
    Re(A),Re(B),Re(C);
    priority_queue <tuple<int64_t,int,int,int>> ppq;
    queue <int64_t> pq;
    ppq.push(make_tuple(A[0]+B[0]+C[0],0,0,0));
    p[make_tuple(0,0,0)]++;
    int a=0,b=0,c=0;
    rep(i,k){
        int64_t t,q,w,e;
        tie(t,q,w,e) = ppq.top();
        ppq.pop();
        //cout<<t<<" "<<q<<" "<<w<<" "<<e<<endl;
        if(q+1<x && p[make_tuple(q+1,w,e)]==0){
           // cout<<"P1"<<endl;
            p[make_tuple(q+1,w,e)]++;
            ppq.push(make_tuple(A[q+1]+B[w]+C[e],q+1,w,e));
        }
        if(w+1<y && p[make_tuple(q,w+1,e)]==0){
            //cout<<"P2"<<endl;
            p[make_tuple(q,w+1,e)]++;
            ppq.push(make_tuple(A[q]+B[w+1]+C[e],q,w+1,e));
        }
        if(e+1<z && p[make_tuple(q,w,e+1)]==0){
            //cout<<"P3"<<endl;
            p[make_tuple(q,w,e+1)]++;
            ppq.push(make_tuple(A[q]+B[w]+C[e+1],q,w,e+1));
        }
        cout<<t<<endl;
        pq.push(t);

    }
    /*
    rep(i,k){
        cout<<pq.front()<<endl;
        pq.pop();
    }
    */
}
