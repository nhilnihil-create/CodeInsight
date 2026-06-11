#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100003;

int main(){
    
    int N;cin>>N;
    if(N==3) cout<<"2 5 63"<<endl;
    else if(N==4) cout<<"2 5 20 63"<<endl;
    else{
        if(N<=15002){
            cout<<"3 9";
            if((N-2)%3==1){
                for(int i=1;i<=N-4;i++){
                    cout<<" "<<i*2;
                }
                cout<<" "<<(N-2)*2<<" "<<(N-1)*2<<endl;
            }else{
                for(int i=1;i<=N-2;i++){
                    cout<<" "<<i*2;
                }
                cout<<endl;
            }
        }else{
            if(N%2==0){
                for(int i=1;i<=15000;i++){
                    if(i>=2) cout<<" ";
                    cout<<i*2;
                }
                for(int i=1;i<=N-15000;i++){
                    cout<<" "<<i*6-3;
                }
                cout<<endl;
            }else{
                cout<<"2 4";
                for(int i=4;i<=15000;i++){
                    cout<<" "<<i*2;
                }
                for(int i=1;i<=N-14999;i++){
                    cout<<" "<<i*6-3;
                }
                cout<<endl;
            }
        }
    }
}
