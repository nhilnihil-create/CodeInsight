#include<iostream>
#include<cmath>
using namespace std;

int getDivisor(int index){
    int count=0;
    for(int i=2;i<=sqrt(index);i++){
        if(index%i==0){
            count++;
            if(index!=i*i){
                count++;
            }
        }
    }
    return count+2;
}
int main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=0;i<=n;i++)
    {
        if(i%2!=0){
            if(getDivisor(i)==8){
                count++;
            }
        }
    }
    cout<<count<<endl;
}