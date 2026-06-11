#include<iostream>
using namespace std;
int main(){
    int n,x,d;
    cin>>n>>d>>x;
    int result=0;
    int factor=(d*(d+1))/2;
    for(int i=0;i<n;i++)
    {
        int element;
        cin>>element;
        int res=(d-1)/(element);
        result+=res+1;
    }
    result+=x;
    cout<<result;
}