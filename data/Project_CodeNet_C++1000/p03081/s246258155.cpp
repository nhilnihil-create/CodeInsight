#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=100001,INF=1<<30;

int main(){

  int N,Q,ans=0;cin>>N>>Q;
    string S;cin>>S;
    string A,B;
    for(int i=0;i<Q;i++){
        string a,b;cin>>a>>b;
        A+=a;
        B+=b;
    }
    int left=0,right=N-1;
    while(left!=right){
        int mid=(left+right)/2;
        int now=mid;
        bool okleft=false,okright=false;
        for(int i=0;i<Q;i++){
            if(A[i]==S[now]){
                if(B[i]=='L') now--;
                else now++;
            }
            if(now==-1){
                okleft=true;
                break;
            }
            if(now==N){
                okright=true;
                break;
            }
        }
        if(okleft) left=mid+1;
        else right=mid;
    }
    
    bool okleft=false,okright=false;
    int now=left;
    for(int i=0;i<Q;i++){
        if(A[i]==S[now]){
            if(B[i]=='L') now--;
            else now++;
        }
        if(now==-1){
            okleft=true;
            break;
        }
        if(now==N){
            okright=true;
            break;
        }
    }
    if(okleft) ans+=left+1;
    else ans+=left;
    
    //cout<<left<<" "<<ans<<endl;
    
    left=0;right=N-1;
    while(left!=right){
        int mid=(left+right)/2;
        int now=mid;
        bool okleft=false,okright=false;
        for(int i=0;i<Q;i++){
            if(A[i]==S[now]){
                if(B[i]=='L') now--;
                else now++;
            }
            if(now==-1){
                okleft=true;
                break;
            }
            if(now==N){
                okright=true;
                break;
            }
        }
        if(okright) right=mid;
        else left=mid+1;
    }
    
    okleft=false;okright=false;
    now=left;
    for(int i=0;i<Q;i++){
        if(A[i]==S[now]){
            if(B[i]=='L') now--;
            else now++;
        }
        if(now==-1){
            okleft=true;
            break;
        }
        if(now==N){
            okright=true;
            break;
        }
    }
    if(okright) ans+=(N-left);
    else ans+=(N-1-left);
    
    //cout<<ans<<endl;
    
    cout<<N-ans<<endl;
    
}
