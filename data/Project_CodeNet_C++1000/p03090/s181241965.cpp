#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,ans=0;
    cin >> N;
    if(N%2==0){
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(i+j!=1+N){
                    ans++;
                }
            }
        }
    }else{
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(i+j!=N){
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    if(N%2==0){
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(i+j!=1+N){
                    cout << i << " " << j << endl;
                }
            }
        }
    }else{
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(i+j!=N){
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    
}