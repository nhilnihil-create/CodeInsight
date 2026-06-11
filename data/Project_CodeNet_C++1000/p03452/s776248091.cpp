#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>
#include <random>

using namespace std;

#define INT_MAX_VALUE 2147483647
#define LONG_LONG_MAX_VALUE 9223372036854775807
#define ll long long
#define ld long double

struct XX{
    int s;
    int t;
    int c;
};

class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.t) == (riRight.t)){
            return riLeft.s < riRight.s;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
            //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.t) < (riRight.t);
    }
};


//map<long long,long long> prime_f(long long n){
//    map<long long,long long>res;
//    for(int i=2;i*i<=n;i++){
//        while(n%i==0){
//            ++res[i];
//            n/=i;
//        }
//    }
//    if(n!=1)res[n]=1;
//    return res;
//}

//int n;
////int dat[2*10000000];
////int dat2[2*10000000];
//int dat[10];
//int dat2[10];
//
//void init(int n_){
//    n=1;
//    while(n<n_)n*=2;
//    for(int i=0;i<2*n-1;i++){
//        dat[i]=0;
//        dat2[i]=0;
//    }
//}
//
//void initset(int k,int a){
//    k+=n-1;
//    dat[k]=a;
//    while(k>0){
//        k=(k-1)/2;
//        dat[k]=dat[k*2+1]+dat[k*2+2];
//    }
//}
//
////[a,b)の間を[l,r]区間で比較しアップデート
////引数のindexに注意
////nは固定。initで計算すみ
////update2(L[i],R[i]+1,0,0,n,D[i]);
//void update2(int a,int b,int k,int l,int r,int v){//v更新値、区間は0-index
//    if(r<=a || b<=l)return;
//    if(a<=l && r<=b){
//        dat[k]+=dat2[k];
//        if(r-l>1){
//            dat2[k*2+1]+=dat2[k]/2;
//            dat2[k*2+1]+=dat2[k]/2;
//        }
//        dat2[k]=v*(r-l);
//        return;
//    }else{
//        update2(a,b,k*2+1,l,(l+r)/2,v);
//        update2(a,b,k*2+2,(l+r)/2,r,v);
//        return;
//    }
//}
//
//int query(int a,int b,int k,int l,int r){
//    if(r<=a || b<=l)return 0;
//    if(a<=l && r<=b){
//        dat[k]+=dat2[k];
//        if(r-l>1){
//            dat2[k*2+1]+=dat2[k]/2;
//            dat2[k*2+1]+=dat2[k]/2;
//        }
//        dat2[k]=0;
//        return dat[k];
//    }
//    else{
//        int vl=query(a,b,k*2+1,l,(l+r)/2);
//        int vr=query(a,b,k*2+2,(l+r)/2,r);
//        return vl+vr;
//    }
//}




int ppar[100001]; //親(1-index)
int rrank[100001];//木の深さ
int diff_weight[100001];

void init(int n){//
    for(int i=1;i<=n;i++){
        ppar[i]=i;
        rrank[i]=0;
        diff_weight[i]=0;
    }
}

int find(int x){
    if(ppar[x]==x){
        return x;
    }else{
        int root=find(ppar[x]);
        diff_weight[x]+=diff_weight[ppar[x]];//rootに繋ぎ直し前に加える
        return ppar[x]=root;//rootに繋ぎ直し
    }
}
int weight(int x){
    find(x);
    return diff_weight[x];
}
void unite(int x,int y,int w){//親を設定するだけで、rootに繋ぎ直しはしない
    w+=weight(x)-weight(y);
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(rrank[x]<rrank[y]){
        ppar[x]=y;
        diff_weight[x]=-w;
    }else{
        ppar[y]=x;
        diff_weight[y]=w;
        if(rrank[x]==rrank[y]){
            rrank[x]++;
        }
    }
}
bool same(int x,int y){
    return find(x)==find(y);
}


int main(int argc, const char * argv[])
{
    //scanf("%s",S);
    //scanf("%d",&N);
    //scanf("%lld %lld",&target1,&target2);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //ifstream ifs("a.txt");//テスト用
    //ifs >> a;
    //ここから
    
    //入力高速化
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N,M;
    cin >> N>>M;
    int l[200000];
    int r[200000];
    int d[200000];
    for(int i=0;i<M;i++){
        cin >>l[i]>>r[i]>>d[i];
    }
    init(N);
    for(int i=0;i<M;i++){
        if(same(l[i],r[i])){
            if((weight(r[i])-weight(l[i]))!=d[i]){
                cout << "No" << endl;
                return 0;
            }
        }else{
            unite(l[i],r[i],d[i]);
        }
    }

    cout << "Yes" << endl;
    //ここまで
    //cout << "ans" << endl;
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    
    return 0;
}
