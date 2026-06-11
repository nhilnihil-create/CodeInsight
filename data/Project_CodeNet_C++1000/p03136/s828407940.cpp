#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int max=0,sum=0;
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        if(temp>max){
            sum+=max;
            max=temp;
        }
        else{
            sum+=temp;
        }
    }
    if(max<sum)
        cout<<"Yes"<<endl;
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}