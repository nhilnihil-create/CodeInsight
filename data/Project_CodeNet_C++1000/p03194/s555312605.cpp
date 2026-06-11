#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> vec;
bool isprime(int i){
    if(i==2) return true;
    if(i%2==0) return false;
    else{
        for(int j=3;j<=sqrt(i);j+=2){
            if(i%j==0) return false;
        }
        return true;
    }
}
int check(int n,int i,int p){
    if(p%i!=0) return 0;
    int sum=0;
    int rec=1;
    while(1){
        if(i==0 || p%i!=0) break;
        p/=i;
        sum++;
    }
    //cout<<i<<" "<<sum<<endl;
    if(sum<n) return 0;
    for(int j=0;j<sum/n;j++) rec*=i;
    //cout<<sum/n<<endl;
    return rec;
}
signed main(){
    for(int i=2;i<=1000000;i++){
        if(isprime(i)) vec.push_back(i);
    }
    int n,p;
    int ans=1;
    int tmp;
    cin>>n>>p;
    if(n==1){
        cout<<p<<endl;
        return 0;
    }
    for(int i=0;i<vec.size();i++){
        if(p<vec[i]) break;
        tmp=check(n,vec[i],p);
        //cout<<tmp<<endl;
        if(tmp) ans*=tmp;
    }
    cout<<ans<<endl;
    
    return 0;
}

