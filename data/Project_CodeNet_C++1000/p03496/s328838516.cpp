#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
int main(){
    array<long long,50>a;
    int n,minn,maxn;
    long long min = 1000001;
    long long max = -1000001;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a.at(i);
        if(min > a.at(i)){
            min = a.at(i);
            minn = i;
        }
        if(max < a.at(i)){
            max = a.at(i);
            maxn = i;
        }
    }
    if(min*max<=0){
      cout<<2*n-1<<endl;
    if(abs(min) >= abs(max)){
        for(int i = 0; i <n;i++){
            cout<<minn+1<<' '<<i+1<<endl;
        }
        for(int i = n; i > 1; i--){
            cout<<i<<' '<<i-1<<endl;
        }
    }else{
        for(int i = 0; i < n; i++){
            cout<<maxn+1<<' '<<i+1<<endl;
        }
        for(int i = 1; i < n; i++){
            cout<<i<<' '<<i+1<<endl;
        }
    }
    }
    if(min > 0 && max > 0){
      cout<<n-1<<endl;
        for(int i = 1; i < n; i++){
            cout<<i<<' '<<i+1<<endl;
    }
    }
    if(min < 0 && max < 0){
      cout<<n-1<<endl;
        for(int i = n; i > 1; i--){
            cout<<i<<' '<<i-1<<endl;
        }
    }
}
