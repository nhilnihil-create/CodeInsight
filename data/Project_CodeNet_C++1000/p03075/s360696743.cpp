#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int k,f=0;
    vector<int> a(5);
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>k;
    for(int i=0;i<5;i++){
        for(int j=0;j<i;j++){
            if(a[i]-a[j]>k){
                f=1;
            }
        }
    }
    if(f==1){
        cout<<":("<<endl;    
        }
        else{
            cout<<"Yay!"<<endl;
        }
    return 0;
}