#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    string  S[1000];
    int poi[1000];
    int moto[1000];
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>S[i]>>poi[i];
        moto[i]=i;
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            if(S[j]>S[j+1]||(S[j]==S[j+1]&&poi[j]<poi[j+1])){
                swap(S[j],S[j+1]);
                swap(poi[j],poi[j+1]);
                swap(moto[j],moto[j+1]);
            }
        }
    }
    for(int i=1;i<=N;i++){
        cout<<moto[i]<<endl;
    }
    return 0;
}
