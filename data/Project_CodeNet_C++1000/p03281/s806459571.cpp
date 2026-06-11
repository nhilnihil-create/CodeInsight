#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void){
    // Your code here!
    long long int N,H,W,x,i,j,k,ans,count,cost,tmp;
    long long int S[200010];
    long long int Ssum[200010];
    string T,U,V,ans2;
    bool flag;
    count=0;
    ans=std::pow(10,18);
    ans=0;
    flag=false;
        cin >> N;
        count=0;
    
    
        for (i=1;i<=N;i=i+2){
            count=0;
            for (j=1;j<=i;j++){
                if (i%j==0){
                    count+=1;
                }
            }
            if (count==8){
                ans+=1;
            }
            //cout << i<<endl;

        }

    
    
    cout << ans<<endl;

    return 0;
    
}
