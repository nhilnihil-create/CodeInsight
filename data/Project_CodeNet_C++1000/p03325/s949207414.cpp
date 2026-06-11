#include <iostream>
#include <algorithm>

#define rep(i,n) for(int i=0;i!=(n);++i)

using namespace std;

typedef long long ll;

int count_arr(ll a){
    int num=0;
    while(true){
        if(a%2==0){
            a=a/2;
            ++num;
        }else{
            break;
        }
    }
    return num;
}


int main(){

    int N;
     scanf("%d",&N);

    ll a[N];

    ll count=0;

    rep(i,N){
        cin>>a[i];
        count+=count_arr(a[i]);
    }

    cout<<count<<endl;    
}

