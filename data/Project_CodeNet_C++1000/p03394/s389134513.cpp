#include <iostream>
using namespace std;
int n,N;
int main(void){
    cin>>n;
    if(n==3){
        cout<<"2 5 63"<<endl;
        return 0;
    }
    if(n==4){
        cout<<"2 5 20 63"<<endl;
        return 0;
    }
    cout<<"2 3 4 9 ";
    N=n-4;
    if(N%2==1){
        cout<<6<<" ";
    }
    for(int i=1;i<=min(4999,(N-N%2)/2);i++){
        cout<<6*i+2<<" "<<6*i+4<<" ";
    }
    n-=9998+5;
    if(n>=0&&N%2==0)cout<<6<<" "<<endl;
    if(n<=0){cout<<endl;return 0;}
    if(n==9997){n--;cout<<12<<" ";}
    for(int i=0;i<(n-1)/4;i++){
        cout<<12*i+27<<" "<<12*i+30<<" "<<12*i+33<<" "<<12*i+36<<" ";
    }
    //cout<<n<<endl;
    N=n%4;
    if(N==0)N=4;
    if(N==1){
        cout<<18<<endl;
        return 0;
    }
    if(N==2){
        cout<<18<<" "<<24<<endl;
        return 0;
    }
    for(int i=0;i<N;i++){
        cout<<3*i+15<<" ";
    }
    cout<<endl;
}
