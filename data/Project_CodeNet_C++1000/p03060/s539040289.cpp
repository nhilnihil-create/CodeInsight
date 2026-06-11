# include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int main(){
    int n;
    cin>>n;
    int v[n],c[n];
    for(int i=0;i<n;i++)
        cin>>v[i];
     for(int i=0;i<n;i++)
        cin>>c[i];
    int sum=0;
    for(int i=0;i<n;i++){
        if(v[i]>c[i])
            sum+=(v[i]-c[i]);
           
    }
    cout<<sum;
    return 0;
}