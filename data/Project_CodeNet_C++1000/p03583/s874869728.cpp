#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iomanip>
#include <math.h>
using namespace std;
int main(){
    long long int n,f=0;
    cin>>n;
    for(long long int i=1;i<=3500;i++){
        for(long long int j=1;j<=3500;j++){
            if((4*i*j-n*(i+j))!=0){
                if(((n*i*j)%(4*i*j-n*(i+j)))==0&&((n*i*j)/(4*i*j-n*(i+j)))>0){
                    cout<<i<<' '<<j<<' '<<(n*i*j)/(4*i*j-n*(i+j))<<endl;
                    f=1;
                    break;
                }
            }
        }
        if(f==1){
            break;
        }
    }
    return 0;
}
