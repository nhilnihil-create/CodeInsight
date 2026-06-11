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
#include <numeric>

using namespace std;

#define I_MAX 2147483647
#define LL_MAX 9223372036854775807
#define ll long long
#define ld long double

struct XX{
    string s;
    int p;
    int c1;
    int c2;
    int num;
};

class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.s) == (riRight.s)){
            return riLeft.p < riRight.p;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
            //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.s) < (riRight.s);
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



//void printb(unsigned int v) {
//    unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
//    do putchar(mask & v ? '1' : '0');
//    while (mask >>= 1);
//}


#ifdef DEBUG

#else

#endif

int prime[101];
bool is_prime[101];

int cnt[101];


int cmb(int nn, int kk){
    int bunsi=1;
    int bunbo=1;
    for(int i=0;i<kk;i++){
        bunsi*=(nn-i);
        bunbo*=(kk-i);
    }
    return bunsi/bunbo;
}

int main(int argc, const char * argv[])
{
    //scanf("%s",S);
    //scanf("%d",&N);
    //scanf("%lld %lld",&target1,&target2);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //ifstream ifs("01");//テスト用
    //ifs >> a;
    //ここから
    
    //入力高速化
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int p=0;
    for(int i=0;i<=101;i++){
        is_prime[i]=true;
    }
    is_prime[0]=false;
    is_prime[1]=false;
    for(int i=2;i<=101;i++){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=2*i;j<=101;j+=i){
                is_prime[j]=false;
            }
        }
    }
    
    int N;
    cin>>N;
    for(int i=2;i<=N;i++){
        int tmp=i;
        for(int j=2;j<=N;j++){
            if(is_prime[j]&&tmp%j==0){
                cnt[j]++;
                tmp/=j;
                j--;
            }
        }
    }
    int ans=0;
    for(int i=0;i<101;i++){
        if(cnt[i]>=74){
            ans++;
        }
    }
    int t1=0;
    int t2=0;
    for(int i=0;i<101;i++){
        if(cnt[i]>=4){
            t1++;
        }
        if(cnt[i]>=14){
            t2++;
        }
    }
    if(t2*(t1-1)>0){
        ans+=t2*(t1-1);
    }
    t1=0;
    t2=0;
    for(int i=0;i<101;i++){
        if(cnt[i]>=2){
            t1++;
        }
        if(cnt[i]>=24){
            t2++;
        }
    }
    if(t2*(t1-1)>0){
        ans+=t2*(t1-1);
    }
    t1=0;
    t2=0;
    for(int i=0;i<101;i++){
        if(cnt[i]>=2){
            t1++;
        }
        if(cnt[i]>=4){
            t2++;
        }
    }
    if((t2-1)>0&&(t1-2)>0){
        ans+=cmb(t2,2)*(t1-2);
    }
    
    cout << ans << endl;

    //ここまで
    //cout << "ans" << endl;
    //cout << " " << "ans" << endl;
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    
    return 0;
}
