#include<bits/stdc++.h>
using namespace std;
int x[100];
int y[100];
int h[100];
 
int main(){
    int n;cin>>n;
    int cx_a,cy_a,h_a;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>h[i];
    }
    // cx,cyで全探索
    for(int cx=0;cx<101;cx++){
        for(int cy=0;cy<101;cy++){
            int H;
            for(int i=0;i<n;i++){
                // hが0の時は使わない
                if(h[i]==0) continue;
                // cx,cyのときのhを求める
                H=h[i]+abs(x[i]-cx)+abs(y[i]-cy);
                break;
            }
            for(int i=0;i<n;i++){
                // ありうる点なのか検証。だめだったら最初から
                if(h[i]!=max(H-abs(x[i]-cx)-abs(y[i]-cy),0)) break;
                // 最後まで探索したら
                if(i==n-1){
                    cx_a=cx;
                    cy_a=cy;
                    h_a=H;
                }
            }
        }
    }
    cout<<cx_a<<' '<<cy_a<<' '<<h_a<<endl;
}