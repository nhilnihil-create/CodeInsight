#include<iostream>

using namespace std;

int main(){
    int N;
    int a[50];
    cin>>N;
    int AbsMaxInd;
    int AbsMax=-1;
    for(int i=0;i<N;i++){
        cin>>a[i];
        if(abs(a[i]) > AbsMax){
            AbsMax=abs(a[i]);
            AbsMaxInd=i;
        }
    }
    AbsMaxInd++;
    if(AbsMax==0){
        cout<<0<<endl;
    }else if(a[AbsMaxInd-1]>0){//絶対値の一番大きい数が正の時
        cout<<(2*(N-1))<<endl;
        for(int i=1;i<=N;i++){
            if(i != AbsMaxInd){
                cout<< AbsMaxInd << ' ' << i <<endl;
            }
        }
        for(int i=1;i<N;i++){
            cout<< i << ' ' << (i+1) <<endl;
        }
    }else{//絶対値の一番大きい数が負の時
        cout<<(2*(N-1))<<endl;
        for(int i=1;i<=N;i++){
            if(i != AbsMaxInd){
                cout<< AbsMaxInd << ' ' << i <<endl;
            }
        }
        for(int i=N;i>1;i--){
            cout<< i << ' ' << (i-1) <<endl;
        }
    }
    
    
    return 0;
}
