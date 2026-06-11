#include<bits/stdc++.h>
using namespace std;
int main(){
    int s;
    cin>>s;
    int arr[1000001];
    arr[1]=s;
    for(int i=2;i<1000001;i++){
        if (arr[i-1]%2==0){
            arr[i]=arr[i-1]/2;
        }
        else if (arr[i-1]%2==1){
            arr[i]=(arr[i-1]*3)+1;
        }
    }
    for(int i=2;i<1000001;i++){
        for(int j=0;j<i;j++){
            if (arr[i]==arr[j]){
                cout<<i<<endl;
    return 0;
            }
        }
    }
}