#include <iostream>
using namespace std;
int main() {
    int n, i, max, max2;
    bool t;
    cin>>n;
    int v[n], v2[n];
    max = 0;
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    for(i=0;i<n;i++){
        if(v[i]>max){max = v[i];}
    }
    for(i=0;i<n;i++){
        if(v[i]>max/2){
            v[i] = max-v[i];
            v2[i] = 1;
        }
    }
    max2 = max;
    max = 0;
    for(i=0;i<n;i++){
        if(v[i]>max){max = v[i]; if(v2[i]== 1){t= true;} else{t=false;}}
    }
    if(t==false){
            cout<<max2<<' '<<max;
    }
    else{
        cout<<max2<<' '<<max2-max;
    }
}
