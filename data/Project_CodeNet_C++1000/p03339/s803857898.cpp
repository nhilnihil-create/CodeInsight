#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N;cin>>N;
    string s;cin>>s;
    int min=N;
    int sumE[N];//Eの累積和
    int sumW[N];//Wの累積和
    int e,w;
    int count;
    rep(i,N){
        if(i==0){
            if(s.at(0)=='E'){
                sumE[0]=1;
                sumW[0]=0;
            }else{
                sumE[0]=0;
                sumW[0]=1;
            }
        }else{
            if(s.at(i)=='E'){
                sumE[i]=sumE[i-1]+1;
                sumW[i]=sumW[i-1];
            }else{
                sumE[i]=sumE[i-1];
                sumW[i]=sumW[i-1]+1;
            }
        }
    }
    e=sumE[N-1];
    w=sumW[N-1];
    for(int i=0;i<N;i++){
        count=0;
        if(i==0){
            count=sumE[N-1]-sumE[0];
        }else if(i==N-1){
            count=sumW[N-2];
        }else{
            count+=sumW[i-1];
            count+=(e-sumE[i]);
        }
        if(count<min){
            min=count;
        }
    }
    cout<<min<<endl;

}