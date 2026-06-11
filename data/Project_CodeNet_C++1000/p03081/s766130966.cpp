#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

int N,Q;
string s;
pair<char,char>td[200010];
int Deleted(int n){
    for(int i=0;i<Q;i++){
        if(s[n]==td[i].first){
            if(td[i].second=='L'){
                n--;
            }else{
                n++;
            }
        }
        if(n<0) return 0;
        if(n>N-1)return 2;
    }
    return 1;
}

int main(){
    cin>>N>>Q>>s;
    for(int i=0;i<Q;i++){
        cin>>td[i].first>>td[i].second;
    }

    if(N<=2){
        int ans=0;
        for(int i=0;i<N;i++){
            if(Deleted(i)==1){
                ans++;
            }
        }
        cout<<ans<<endl;
        return 0;
    }

    int ansL;
    int l=0,r=N-1;
    while(1){
        if(r-l <= 1){
            if(Deleted(r)==0){
                ansL=r+1;
            }else{
                ansL=r;
            }
            break;
        }
        int c=(l+r)/2;
        if(Deleted(c)==0){
            l=c;
        }else{
            r=c;
        }
    }
    int ansR;
    l=0;r=N-1;
    while(1){
        if(r-l <= 1){
            if(Deleted(r)==2){
                ansR=r;
            }else{
                ansR=r+1;
            }
            break;
        }
        int c=(l+r)/2;
        if(Deleted(c)==2){
            r=c;
        }else{
            l=c;
        }
    }
    cout<<ansR-ansL<<endl;
    return 0;
}