#include<bits/stdc++.h>
using namespace std;

int main(){
int n;
cin>>n;
int hano=0;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(4*i+7*j==n)
            hano=1;
    }
}
if(hano==1){
    cout<<"Yes"<<endl;
}
else{
    cout<<"No"<<endl;
}
return 0;
}
