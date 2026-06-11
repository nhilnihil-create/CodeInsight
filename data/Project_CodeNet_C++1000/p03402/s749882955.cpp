#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

char ans[105][105];

int main(){
    int a,b;
    for (int i = 0 ; i < 100;i++){
        for (int j = 0;j < 100; j++){
            if ( j < 50) ans[i][j] = '#';
            else ans[i][j] = '.';
        }
    }
//    for (int i = 0; i < 100;i++){
//        for (int j = 0;j < 100; j++){
//            cout<< ans[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    ###...
//    ###...
//    ###...
    //左白右黑填表
    cin>>a>>b;
    int k = 0;
    for (int i = 0;i < 100; i+=2){
        for (int j = 0;j < 50;j++){
            if ((i+j)%2==0){
                if(a!=1){
                    ans[i][j] = '.';
                    a--;
                }
                else{
                    k = 1;
                    break;
                }
            }
        }
        if(k){
            break;
        }
    }
    k = 0;
    for (int i = 0; i < 100;i+=2){
        for (int j = 50;j < 100;j++){
            if ((i+j)%2==1){
                if(b!=1){
                    ans[i][j] = '#';
                    b--;
                }
                else{
                    k =1;
                    break;
                }
            }
        }
        if (k == 1){
            break;
        }
    }
    cout<<100<<" "<<100<<endl;
    for (int i = 0;i < 100;i++){
        for (int j = 0;j < 100; j++){
            if (j == 99){
                cout<<ans[i][j]<<endl;
            }
            else{
                cout<<ans[i][j];
            }
        }
    }
}
