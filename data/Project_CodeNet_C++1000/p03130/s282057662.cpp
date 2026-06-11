#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(void){
    // Your code here!
    int a;
    int d[10]={0};
    for(int i=0;i<6;i++){
        cin>>a;
        d[a]++;
    }
    if(d[1]<3&&d[2]<3&&d[3]<3&&d[4]<3) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
