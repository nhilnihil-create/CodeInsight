#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int takahasi,nakahasi,hikuhasi,K;
    cin>>takahasi>>nakahasi>>hikuhasi>>K;

    if(K%2==0){
        K=2;
    }else if(K%2==1){
        K=1;
    }

    if(takahasi==nakahasi==hikuhasi){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=K;i++){
    long long int a=takahasi;
    long long int b=nakahasi;

    takahasi=nakahasi+hikuhasi;
    nakahasi=a+hikuhasi;
    hikuhasi=a+b;

   //cout<<takahasi<<" "<<nakahasi<<" "<<hikuhasi<<endl;
    
    if(takahasi-nakahasi>=1000000000000000000){
        cout<<"Unfair"<<endl;
    }
    }

    cout<<takahasi-nakahasi<<endl;
    
}