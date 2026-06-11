#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,A,B;
    cin>>n;A=0;B=0;
    vector<int> vec(n),a(n),b(n);
        for(int i=0; i<n; i++){
        cin>>vec[i];
        }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    for(int i=0; i<n; i++){
        if(i%2==0){
            a[i/2+1]=vec[i];
        }
        if(i%2==1){
            b[i/2]=vec[i];
        }
    }
    for(int i=0; i<a.size(); i++){
        A+=a[i];
    }
    for(int i=0; i<b.size(); i++){
        B+=b[i];
    }
    cout<<A-B<<endl;
}