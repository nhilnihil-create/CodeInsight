#include<bits/stdc++.h>
using namespace std;
int main(){
    int d,g;
    cin>>d>>g;
    g/=100;
    int p[d],c[d];
    for(int i=0;i<d;i++){
        cin>>p[i]>>c[i];
        c[i]/=100;
    }
    int D=1;
    for(int i=0;i<d;i++)D*=2;
    int m=1000;
    for(int i=0;i<D;i++){//どの難易度を全完するか全探索
        int solve[d]={};
        int x=0,score=0,I=i;
        for(int j=0;j<d;j++){
            if(I%2){
                solve[j]=1;
                score+=(j+1)*p[j]+c[j];
                x+=p[j];
            }
            I/=2;
        }
        if(score<g){
            bool br=0;
            for(int j=d-1;j>=0;j--){
                if(solve[j]==0){
                    for(int k=0;k<p[j];k++){
                        score+=j+1;
                        x++;
                        if(score>=g){
                            br=1;
                            break;
                        }
                    }
                    if(br)break;
                }
            }
        }
        m=min(m,x);
    }
    cout<<m<<endl;
    return 0;
}