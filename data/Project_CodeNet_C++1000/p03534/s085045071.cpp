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

template <class T>
T mymax(T a,T b){
    if(a>=b){
        return a;
    }
    return b;
}
template <class T>
T mymin(T a,T b){
    if(a<=b){
        return a;
    }
    return b;
}
//
//long long gcd(long long a, long long b){
//    if(a<b){
//        swap(a,b);
//    }
//    while(b){
//        long long r = a%b;
//        a=b;
//        b=r;
//    }
//    return a;
//}
//
//long long lcm(long long a, long long b){
//    return (a*b)/gcd(a,b);
//}
//
//long long isPrim(long long a){
//    if(a==1){
//        return a;
//    }
//    for(int i=2;i*i<=a;i++){
//        if(a%i==0){
//            return i;
//        }
//    }
//    return a;
//}
//
struct XX{
    long long x;
    long long y;
    long long ix;
    long long iy;
};

class xxGreater {
public:
    bool operator()(const XX& riLeft, const XX& riRight) const {
        //第2条件
        if((riLeft.x) == (riRight.x)){
            return riLeft.y < riRight.y;//<:昇順(小さいものから順番)、>:降順(大きいものから順番)
            //プライオリティキューの場合は > で、top()すると値の小さいものがとれる
        }
        //第1条件
        return (riLeft.x) < (riRight.x);
    }
};


//
////kruskal
//struct edge{
//    int u;
//    int v;
//    int cost;
//};
//
//bool comp(edge& e1,edge& e2){
//    return e1.cost < e2.cost;
//}
//
//edge es[1000];
//
//long long kruskal(int V,int E){//V:頂点数,E:辺数
//    sort(es,es+E,comp);
//    init(V);
//    long long res = 0;
//    for(int i=0;i<E;i++){
//        edge e = es[i];
//        if(!same(e.u,e.v)){
//            unite(e.u,e.v);
//            res+=e.cost;
//        }
//    }
//    return res;
//}

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



int main(int argc, const char * argv[])
{
    //std::ios::sync_with_stdio(false);
    //scanf("%s",S);
    //scanf("%d",&N);
    //sscanf(tmp.c_str(),"%dd%d%d",&time[i], &dice[i], &z[i]);
    //getline(cin, target);
    //cin >> x >> y;
    //テスト用
    //ifstream ifs( "1_06.txt" );
    //ifs >> a;
    //ここから
    
    //入力高速化
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string S;
    cin >> S;
    int a[3]={0,0,0};
    for(int i=0;i<S.size();i++){
        if(S.substr(i,1)=="a"){
            a[0]++;
        }else if(S.substr(i,1)=="b"){
            a[1]++;
        }else{
            a[2]++;
        }
    }
    sort(a,a+3);
    if(a[2]-a[1]>1){
        cout << "NO" << endl;
        return 0;
    }else if(a[1]-a[0]>1){
        cout << "NO" << endl;
        return 0;
    }else if(a[2]-a[1]==1 && a[1]-a[0]==1){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    //ここまで
    //cout << "ans" << endl;改行含む
    //printf("%.0f\n",ans);//小数点以下表示なし
    //printf("%.7f\n",p);
    //printf("%f\n",pow(2,ans.size()));
    
    return 0;
}

