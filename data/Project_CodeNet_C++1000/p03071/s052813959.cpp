#include<iostream>             
using namespace std;           
                               
int main(){                    
        int a,b;               
        cin >> a >> b;         
        int ans = 0;           
        if(a > b){             
                ans += a;   
                a--;           
        }else{                 
                ans += b;   
                b--;           
        }                      
        if(a > b){             
                ans += a;   
                a--;           
        }else{                 
                ans += b;   
                b--;           
        }                      
        cout << ans << endl;                                                                          
}
