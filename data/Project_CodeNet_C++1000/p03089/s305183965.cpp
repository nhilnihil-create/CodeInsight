#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
        a[i] = -1;
    }

    bool key=true;

    for(int i=n-1;i>=0;i--){
        for(int j=i;j>=0;j--){
            if(b[j] == j+1){
                a[i] = b[j];
                for(int k=j;k<n;k++){
                    b[k] = b[k+1];
                }
                break;
            }
        }
        if(a[i] == -1) key=false;
    }

    if(!key) cout<<-1<<endl;
    else {
        for(int i=0;i<n;i++){
            cout<<a[i]<<endl;
        }
    }
}