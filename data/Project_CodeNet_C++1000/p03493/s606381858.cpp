#include<iostream>
using namespace std;
int main(){
    int n;
    int count=0;
    cin>>n;
    int s1=n%10;
    n/=10;
    int s2=n%10;
    n/=10;
    int s3=n%10;
    if(s1==1){
        count++;
    }
    if(s2==1)
    count++;
    if(s3==1)
    count++;
    cout<<count;
}