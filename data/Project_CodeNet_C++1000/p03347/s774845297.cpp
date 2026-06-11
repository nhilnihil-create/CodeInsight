#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N; cin >> N;
    long long a[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    if(a[0]!=0){
        cout << -1 << endl;
        return  0;
    }
    for(int i=1;i<N;i++){
        if(a[i]-a[i-1]>1){
            cout << -1 << endl;
            return 0;
        }
    }
    long long ans=0;
    for(int i=1;i<N;i++){
        if(a[i-1]<a[i]){
            ans+=a[i]-a[i-1];
        }else{
            ans+=a[i];
        }
    }
    cout << ans << endl;

}