#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int max=0;//絶対値最大のやつ
    int maxindex=0;//それの番号
    
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(abs(a)>=abs(max)){
            max=a;
            maxindex=i;
        }
    }
    
    maxindex++;//1-indexedに変換
    
    int m=2*n-1;//操作の回数
    cout<<m<<endl;
    
    //Step 1:絶対値最大のやつを他に足して符号を揃える
    for(int i=1;i<=n;i++){
        cout<<maxindex<<" "<<i<<endl;
    }
    
    //Step 2:前or後ろから順に足していく
    if(max>=0){
        for(int i=1;i<n;i++){
            cout<<i<<" "<<i+1<<endl;
        }
    }else{
        for(int i=n;i>1;i--){
            cout<<i<<" "<<i-1<<endl;
        }
    }
    
    return 0;
}
