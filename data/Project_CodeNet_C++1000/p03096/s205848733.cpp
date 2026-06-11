#include<iostream>
#include<vector>
using namespace std;
struct stone{
    int color=0;
    int to_add=0;
};
int main(){
    int N;
    int mod=1e9+7;
    cin>>N;
    stone stones[200000];
    int out=1;
    int temp,last;
    int colors[N];
    for(int i=0;i<N;i++){
        cin>>colors[i];
    }
    for(int i=0;i<N;i++){
        temp=colors[i];
        if(i&&temp==last)
            continue;
        else
            last=temp;
        bool in=false;
        if(stones[temp].to_add)/*有记录*/{
            out+=stones[temp].to_add;
            out=out%mod;
            stones[temp].to_add=out;
            in = true;
        }
        else{
            stones[temp].color=temp;
            stones[temp].to_add=out;
        }//新颜色
    }
    cout<<out<<endl;
    return 0;
}