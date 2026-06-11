#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin>> n >> a >> b;

    int ans=0;
    for(int i=0; i<n+1; i++){
        string tmp = to_string(i);
        int sum=0;

        for(auto t : tmp){
            sum += t - '0';
        }
        //cout<<i<<" : "<<sum<<endl;
        if(sum<a){
            continue;
        }
        if(sum>b){
            continue;
        }

        ans += i;
    }

    cout<< ans << endl;
    return 0;
}