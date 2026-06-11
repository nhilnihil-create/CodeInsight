#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define rep(i,n) for(int i=0;i<(n);++i)


using namespace std;

typedef long long ll;

int main(){
    int N,Q,l,r;
    scanf("%d %d",&N,&Q);

    char str[N+1];
    int str_num[N+1];
    rep(i,N)str_num[i]=0;
     scanf("%s",str); 
     int q=0;  

    for(int i=1;i!=N;++i){
        if(str[i-1]=='A'&&str[i]=='C'){
            ++q;
            
        }
        str_num[i]=q;
    }
    //rep(i,N)cout<<str_num[i]<<" ";
    //cout<<endl;

    int count;

    rep(i,Q){

        count=0;

        scanf("%d",&l);
        l-=1;
        scanf("%d",&r);
        r-=1;
        count=str_num[r]-str_num[l];

        cout<<count<<endl;

    }
}