#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int total=0;

    for(int i=1;i<=n;i++){
            int y=i;
            int sum=0;
           // while(y>0){
             //   sum=sum+(y%10);
          //      int y=y/10;
        //    }//
            for(int j=0;j<5;j++){
            if(y<=0){
                break;
            }
            int m=y%10;
                sum=sum+m;
                y=y/10;

            }





            if((sum>=a)&&(sum<=b)){
                  
                total=total+i;

            }

    }
    cout<<total<<endl;
}
