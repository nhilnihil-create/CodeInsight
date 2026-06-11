#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll box[3][1000000];//1e6までが'0'に、それ以上は、'1'に値、'2'に個数
int cnt_box;
void soinsuu(ll n){
    for(ll i=2;i*i<=n;i++){
        while(n%i==0){
            if(i<1e6)box[0][i]++;
            else{
                if(cnt_box!=0&&box[1][cnt_box-1]==i){
                    box[2][cnt_box-1]++;
                }   
                else{
                    box[1][cnt_box]=i;
                    box[2][cnt_box]++;
                    cnt_box++;
                } 
            }
            n/=i;    
        }
        if(n==1)break;
    } 
}
int main(){
    ll n,p;
    cin>>n>>p;
    if(n==1){
        cout<<p<<endl;
        return 0;
    }
    soinsuu(p);
    ll ans=1;
    for(ll i=2;i*i<=p;i++){
        while(box[0][i]>=n){
            ans*=i;
            box[0][i]-=n;
        }
    }
    if(cnt_box!=0){
        for(int i=0;i<cnt_box;i++){
            while(box[2][i]>=n){
                ans*=box[1][i];
                box[2][i]-=n;
            }
        }
    }
    cout<<ans<<endl;
}