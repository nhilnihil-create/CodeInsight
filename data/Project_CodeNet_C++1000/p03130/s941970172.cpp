#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const int INF=1e9;
const ll LINF=(ll)1e18;

int main(){
    int a[3],b[3];
    for(int i=0;i<3;i++){
        cin>>a[i]>>b[i];
    }
    int p[4]={1,2,3,4};
    do{
        bool flag=true;
        for(int i=0;i<3;i++){
            bool can=false;
            for(int j=0;j<3;j++){
                if(p[i]==a[j]&&p[i+1]==b[j])can=true;
                else if(p[i]==b[j]&&p[i+1]==a[j])can=true;
            }
            if(!can)flag=false;
        }
        if(flag){
            cout<<"YES"<<endl;
            return 0;
        }
    }while(next_permutation(p,p+4));
    cout<<"NO"<<endl;
}
