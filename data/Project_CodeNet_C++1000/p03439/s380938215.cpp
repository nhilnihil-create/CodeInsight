#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;

int main(){
    string s;
    int N;cin>>N;
    int l=0,r=N;
    vector<int> seat(N+1);
    cout<<0<<endl;
    fflush(stdout);
    cin>>s;
    if(s=="Male"){
        seat[0]=seat[N]=0;
    }
    else if(s=="Female"){
        seat[0]=seat[N]=1;
    }
    else return 0;
    REP(i,19){
        int mid=(l+r)/2;
        cout<<mid<<endl;
        fflush(stdout);
        cin>>s;
        if(s=="Male"){
            seat[mid]=0;
        }
        else if(s=="Female"){
            seat[mid]=1;
        }
        else return 0;
        if(((mid-l)&1)^(seat[l]^seat[mid])){
            r=mid;
        }
        else{
            l=mid;
        }
    }
}
