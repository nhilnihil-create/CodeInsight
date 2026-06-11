#include <iostream>
using namespace std;
int main(void){
    int n,x=2,y=1,z[500][500];
    cin>>n;
    while(n>y){
        y+=x;
        x++;
    }
    if(n!=y){
        cout<<"No"<<endl;
        return 0;
    }
    
    int a=0,c=0;
    for(int i=1;i<=n;i++){
        z[a][a+c]=i;
        z[1+a+c][a]=i;
        c++;
        if(a+c==x-1){
            a++;
            c=0;
        }
    }
    
    
    cout<<"Yes"<<endl;
    cout<<x<<endl;
    for(int i=0;i<x;i++){
        cout<<x-1<<" ";
        for(int j=0;j<x-2;j++){
            cout<<z[i][j]<<" ";
        }
        cout<<z[i][x-2]<<endl;
    }
}
