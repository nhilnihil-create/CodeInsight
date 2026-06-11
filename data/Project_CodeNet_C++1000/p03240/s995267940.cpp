#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[n],y[n],h[n];
    int a_h;
    int flag;
    for(int i=0;i<n;i++)cin >> x[i] >> y[i] >> h[i];
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            flag=0;
            a_h=0;
            for(int k=0;k<n;k++){
                if(a_h==0 && h[k]>0)a_h=h[k]+abs(i-x[k])+abs(j-y[k]);
                else if(a_h>0 && h[k]>0){
                    if(a_h!=h[k]+abs(i-x[k])+abs(j-y[k])){
                        flag++;
                        break;
                    }}
                else if(a_h>0){
                    if(a_h-abs(i-x[k])-abs(j-y[k])>0){
                        flag++;
                        break;
                    }
                }
            }
            if(flag==0){
            for(int k=0;k<n;k++){
                if(h[k]>0){
                    if(a_h!=h[k]+abs(i-x[k])+abs(j-y[k])){
                        flag++;
                        break;
                    }}
                else{
                    if(a_h-abs(i-x[k])-abs(j-y[k])>0){
                        flag++;
                        break;
                    }
                }
            }}
            if(flag==0){
                cout << i << " " << j << " " << a_h << endl;
                break;
            }
        }
        if(flag==0)break;
    }
}