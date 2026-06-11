#include<bits/stdc++.h>

using namespace std ; 

const int N = 3e4 + 7 ;

bool vis[N] ;
int rem ; 

int roof = N - 7 ; 

void add(int x){
        if(vis[x])
                return ; 
        vis[x] = 1; 
        cout<< x<<" "; 
        rem -- ; 
}

int main(){
       // freopen("in.in" , "r" ,stdin) ; 
        int n ; 
        cin >> n; 
        rem = n ; 

        if(n == 3){
                cout<< "2 5 63" ;
        }
        else{
                add(2) ; add(3) ; add(4) ; add(9) ;
                int cur6 = 15  ;
                while(rem > 1 && cur6 + 6 < roof ){
                        add(cur6) ; 
                        add(cur6+6) ; 
                        cur6+=12 ;
                }
                int cur24 = 8 ; 
                while(rem > 1 && cur24 + 2 < roof){
                        add(cur24) ; 
                        add(cur24 +2) ; 
                        cur24+=6 ; 
                }

                int cur60 = 6 ; 

                while(rem && cur60 <= roof){
                        add(cur60) ; 
                        cur60+= 6 ; 
                }

               
        }

        return 0 ;
}