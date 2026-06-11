#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
using P=pair<int,int>;
using ll=long long;
int main(){
    int m,k;
    cin>>m>>k;
    if(pow(2,m)<=k){
        cout<<-1<<endl;
        return 0;
    }
    if(k==0){
        for(int i=0;i<pow(2,m)-1;i++){
            cout<<i<<" "<<i<<" ";
        }
        cout<<pow(2,m)-1<<" "<<pow(2,m)-1<<endl;
        return 0;
    }
    int x=0;
    for(int i=1;i<pow(2,m);i++){
        if(i!=k){
            x^=i;
        }
    }
    if(k==x){
        cout<<k<<" ";
        for(int i=0;i<pow(2,m);i++){
            if(i!=k)cout<<i<<" ";
        }
        cout<<k<<endl;
        for(int i=pow(2,m)-1;i>=1;i--){
            if(i!=k)cout<<i<<" ";
        }
        cout<<0<<endl;
    }else{
        cout<<-1<<endl;
    }
}

