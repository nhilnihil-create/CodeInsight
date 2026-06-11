#include<bits/stdc++.h>

using namespace std ; 

const int N = 1e5 + 7 ; 

int n ; 
int deg[N] ; 
string s ; 

int main(){
    ios_base::sync_with_stdio(0) ; 
    cin.tie(0) ; 
    //freopen("in.in" , "r" , stdin) ;
    cin>>s ;
    n = s.size() ;  
    if(s[n-1] == '1' || s[0] =='0')return cout<< -1 , 0 ;

    for(int i = 0 ; i < n /2 -1; i++){
        if(s[i] !=s[n-2-i])return cout<< -1  , 0 ; 
    }
    int cur =1 ; 
    int t = 2 ; 
    for(int i = n- 2; i >=0 ;i --){
        if(s[i] =='0'){
            cout<< t++ <<" " << cur <<"\n" ; 
        }
        else{
            cout<< t++ <<" " << cur <<"\n" ; 
            cur = t -1; 
        }
    }

    return 0 ;
}
