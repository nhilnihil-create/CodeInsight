#include <bits/stdc++.h>
using namespace std;

//関数
//main関数
int main() {
    
    
    //入力
    long N;
    cin>>N;
    //計算
    //出力
    if(N==3){
        cout<<"2 5 63"<<endl;
    }else{
        long times=N/8,rem=N%8;
        for(int i=0;i<times;i++){
            cout<<12*i+2<<" "<<12*i+3<<" "<<12*i+4<<" "<<12*i+6<<" "<<12*i+8<<" "<<12*i+9<<" "<<12*i+10<<" "<<12*i+12<<" ";
        }
        if(rem==1) cout<<12*times+6;
        if(rem==2) cout<<12*times+2<<" "<<12*times+4;
        if(rem==3) cout<<12*times+2<<" "<<12*times+4<<" "<<12*times+6;
        if(rem==4) cout<<12*times+2<<" "<<12*times+3<<" "<<12*times+4<<" "<<12*times+9;
        if(rem==5) cout<<12*times+2<<" "<<12*times+3<<" "<<12*times+4<<" "<<12*times+6<<" "<<12*times+9;
        if(rem==6) cout<<12*times+2<<" "<<12*times+3<<" "<<12*times+4<<" "<<12*times+8<<" "<<12*times+9<<" "<<12*times+10;
        if(rem==7) cout<<12*times+2<<" "<<12*times+3<<" "<<12*times+4<<" "<<12*times+6<<" "<<12*times+8<<" "<<12*times+9<<" "<<12*times+10;
    }
}