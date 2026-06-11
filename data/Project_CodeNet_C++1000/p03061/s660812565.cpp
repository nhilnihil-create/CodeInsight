//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<climits>

/*
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Bint = mp::cpp_int;
*/

using namespace std;

#define int long long
#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++)
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--)
#define MOD 1000000007

//0-index
vector<int> seqv;
int seqv_n;
int gcd(int a,int b){
    if(a<b) return gcd(b,a);
    if(b==0) return a;
    return gcd(b,a%b);
}

void seg_debug(){
    cout<<"---------seg_debug------n="<<seqv_n<<endl;
    int k=1;
    for(int i=0;i<(seqv_n+1)*2-1;i++){
        if(k==i) {
            cout<<endl;
            k=k*2+1;
        }
        cout<<seqv[i]<<" ";
    }
    cout<<endl<<"------------------------------"<<endl;
}

void seg_init(int N,int a){
    seqv.clear();
    int n=1;
    while(n<N) n*=2;
    seqv_n=n-1;
    n*=2;
    n=n-1;
    for(int i=0;i<n;i++){
        seqv.push_back(a);
    }
}

void seg_update(int n,int a){
    int k=n+seqv_n;
    seqv[k]=a;
    while(k>0){
        k=(k-1)/2;
        if(seqv[k*2+1]==LLONG_MAX) seqv[k]=seqv[k*2+2];
        else if(seqv[k*2+2]==LLONG_MAX) seqv[k]=seqv[k*2+1];
        else seqv[k]=gcd(seqv[k*2+1],seqv[k*2+2]);
    }
}


int seg_find(int x,int y){
    struct segF{
        static int segfind(int x,int y,int k,int l,int r){
            //cout<<x<<","<<y<<","<<k<<","<<l<<","<<r<<endl;
            if(r<x||l>y) return LLONG_MAX;
            if(l>=x&&r<=y) return seqv[k];
            else{
                int segl=segfind(x,y,k*2+1,l,(l+r)/2);
                int segr=segfind(x,y,k*2+2,(l+r)/2+1,r);
                if(segl==LLONG_MAX) return segr;
                if(segr==LLONG_MAX) return segl;
                return gcd(segl,segr);
            }
        }
    };
    return segF::segfind(x,y,0,0,seqv_n);
}

signed main(){
    int n;
    cin>>n;
    seg_init(n,LLONG_MAX);
    for(int i=0;i<n;i++){
        int A;
        cin>>A;
        seg_update(i,A);
    }

    int ans=seg_find(0,n-1);
    for(int i=0;i<n;i++){
        int a=seg_find(i,i);
        seg_update(i,LLONG_MAX);
        ans=max(ans,seg_find(0,n-1));
        seg_update(i,a);
    }
    cout<<ans<<endl;
}
