#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    int a,b,c,x;
    cin>>a>>b>>c>>x;
    int ans=0;
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int k=0;k<=c;k++){
                if(i*500+j*100+k*50==x){
                    ans++;
                }
            }
        }
    }
    cout<<ans;
}

