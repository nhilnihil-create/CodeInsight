#include <iostream>
#include <string>
using namespace std;
int main(void){
    int N;
    cin>>N;
    double sum=0;
    for(int i=0;i<N;i++){
        double a;
        string b;
        cin>>a>>b;
        if(b=="JPY"){
            sum+=a;
        }
        else{
            sum+=a*380000;
        }
    }
    cout<<sum<<endl;
}
