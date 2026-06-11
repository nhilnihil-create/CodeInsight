#include<iostream>
#include<cstdlib>
using namespace std;
int N;
int A[200];
const int INF=1000000000;

int main(){
    //最大値と最小値の絶対値を求める
    cin>>N;
    for(int i=0;i<N;++i)cin>>A[i];
        int res_min=INF;
        int res_max=-INF;
        for(int i=0;i<N;++i){
            if(res_min>A[i])res_min=A[i];
            if(res_max<A[i])res_max=A[i];
        }
    cout<<abs(res_max-res_min);
}