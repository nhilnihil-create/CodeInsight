#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int prev=0;
    int count=0;
    bool no=true;
    while(n!=0)
    {
        int element=n%10;
        n/=10;
        if(prev==-1)
        {
            prev=element;
            count=1;
        }
        else
        if(prev==element)
        {
            count++;
            if(count==3)
            {
                no=false;
                break;
            }
        }
        else
        {
            prev=element;
            count=1;
        }
    }
    if(!no)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
}