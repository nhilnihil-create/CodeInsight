        #include <bits/stdc++.h>
        using namespace std;
		typedef long long int ll;

        int main() {
          ll N,A,B;
          cin>> N >> A >> B; 
          if( A+B -1 > N || A*B < N || A > N || B>N || A<1 || B<1 ){
            cout<< -1 <<endl;
          }
          else if(B==1){
            for(ll i=1; i<=N; i++){
              cout<< i <<" "; 
            }
          }
          else{
            ll T = (N - A )/(B-1);
            ll R = (N - A)%(B-1);
            ll X;
            for(ll i=1; i<= T; i++){
              for(ll j=1; j<= B; j++){
                	cout<< B*i+ + 1 -j <<" ";  
              }
              X= B*i; 
            }
            if(R==0){
            	for(ll i=X+1; i<=N; i++){
              	cout<< i <<" ";
                }
            }else{
              for(ll i=X+1; i<= N-R-1; i++){
                cout<< i <<" ";
              }
              for(ll i=N; i>= N-R; i--){
                cout<< i <<" ";
              }
            }
          }
        }