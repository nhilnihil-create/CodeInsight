#include<iostream>

using namespace std;
int main(){
    int c[3][3];
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                cin>>c[i][j];
            }
        }
    int x[3],y[3];
    x[0]=0;

            for(int i=0;i<3;++i)y[i]=c[0][i];
                for(int i=0;i<3;++i)x[i]=c[i][0]-y[0];
    bool check=true;


    
                    for(int i=0;i<3;++i){
                        for(int j=0;j<3;++j){
                            if(x[i]+y[j]!=c[i][j]){
                                check=false;
                                break;
                            }
                        }
                    }


                        if(check){
                            cout<<"Yes";
                        }else{
                            cout<<"No";
                        }
}
