#include <iostream>
#include <string>
using namespace std;
int main(void){
    int N;
    cin>>N;
    int sum=0;
    int a=0;
    for(int i=0;i<N;i++){
        int price;
        cin>>price;
        sum+=price;
        if(a<price){
            a=price;
        }
    }
    sum-=a/2;
    cout<<sum<<endl;
}
