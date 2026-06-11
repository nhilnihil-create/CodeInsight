#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007;

int main(){
    
    string S;cin>>S;
    int N=S.size();
    
    if(N%2==0){
        int x=N/2;
        for(int i=1;i<N;i++){
            if(S[i]!=S[i-1]){
                x=min(x,abs(N/2-i));
            }
        }
        cout<<N/2+x<<endl;
    }else{
        /*int x=N/2;
        for(int i=1;i<N;i++){
            if(S[i]!=S[i-1]){
                x=min(x,abs(N/2+1-i));
            }
        }
        cout<<N/2+1+x<<endl;*/
        char a=S[N/2-1],b=S[N/2+1],c=S[N/2];
        int cnt1=0,cnt2=0;
        for(int i=N/2-1;i>=0;i--){
            if(S[i]==a) cnt1++;
            else break;
        }
        for(int i=N/2+1;i<N;i++){
            if(S[i]==b) cnt2++;
            else break;
        }
        if(a!=c||b!=c) cout<<N/2+1<<endl;
        else cout<<N/2+1+min(cnt1,cnt2)<<endl;
    }
}
