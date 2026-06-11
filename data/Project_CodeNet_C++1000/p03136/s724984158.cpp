#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>l(n);
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    int sum=0;
    for(int i=0;i<l.size();i++)
    {
        sum+=l[i];
    }
    bool no=false;
    for(int i=0;i<l.size();i++)
    {
        if(sum<=2*l[i]){
            no=true;
            break;
        }
    }
    if(no){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
    }
}