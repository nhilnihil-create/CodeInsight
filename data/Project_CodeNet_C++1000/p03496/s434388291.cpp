#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int main(){
    vec x,y;
    int N;cin>>N;
    int a[60];
    int M=-1,m=1,i_M=0,i_m=0;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        if(a[i]>=0){
            if(a[i]>M){
                M=a[i];
                i_M=i;
            }
        }
        else{
            if(a[i]<m){
                m=a[i];
                i_m=i;
            }
        }
    }
    
    if(M==-1){
        int i=N-1;
        while(i>=1){
            if(a[i]>a[i+1]){
                a[i]+=a[i+1];
                x.push_back(i+1);
                y.push_back(i);
            }
            i--;
        }
    }
    else if(m==1){
        for(int i=1;i<N;i++){
            if(a[i]>a[i+1]){
                a[i+1]+=a[i];
                x.push_back(i);
                y.push_back(i+1);
            }
        }
    }
    else if(M>=-m){
        for(int i=1;i<=N;i++){
            if(a[i]<0){
                a[i]+=M;
                x.push_back(i_M);
                y.push_back(i);
            }
        }
        for(int i=1;i<N;i++){
            if(a[i]>a[i+1]){
                a[i+1]+=a[i];
                x.push_back(i);
                y.push_back(i+1);
            }
        }
    }
    else{
        for(int i=1;i<=N;i++){
            if(a[i]>0){
                a[i]+=m;
                x.push_back(i_m);
                y.push_back(i);
            }
        }
        int i=N-1;
        while(i>=1){
            if(a[i]>a[i+1]){
                a[i]+=a[i+1];
                x.push_back(i+1);
                y.push_back(i);
            }
            i--;
        }
    }

    cout<<x.size()<<endl;
    for(int i=0;i<x.size();i++)
        cout<<x[i]<<" "<<y[i]<<endl;
    return 0;  
}