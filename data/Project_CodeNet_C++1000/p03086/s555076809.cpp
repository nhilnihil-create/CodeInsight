#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    int N,i,j,k,ans,count;
    string S;
    bool flag;
    count=0;
    ans=0;
    flag=false;
    cin >> S;
    
    for (i=0;i<S.size();i++){
        
        if(S[i]=='A' || S[i]=='C' || S[i]=='G' || S[i]=='T'){
            
            if (flag==false){
                flag=true;
                count=1;
                if (count>ans){
                    
                    ans=count;
                }
            
            }
            else{
                
                count+=1;
                if (count>ans){
                    ans=count;
                  
                }
            }
        }
        else{
            flag=false;
            count=0;
        }
        
    }
    
    cout << ans<<endl;

    return 0;
    
}
