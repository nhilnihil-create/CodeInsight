#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <bool> d(n+1);
    d[1]=true;
    for(int i=2;i*i<=n;i++){
        int tmp=i*i;
        while(tmp<=n){
            d[tmp]=true;
            tmp*=i;
        }
    }
    for(int i=n;i>=1;i--){
        if(d[i]){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}