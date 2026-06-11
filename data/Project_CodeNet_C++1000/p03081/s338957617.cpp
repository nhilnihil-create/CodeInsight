#include<iostream>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int N,Q;
    cin>>N>>Q;
    string S;
    cin>>S;
    char t[Q],d[Q];
    int ts=-1,te=N;
    for(int i=0;i<Q;i++){
        cin>>t[i]>>d[i];
    }
    for(int i=Q-1;i>=0;i--){
        if(te-ts<=1)break;
        if(d[i]=='L'){
            if(ts<N-1 && S[ts+1]==t[i])ts++;
            if(te<N && S[te]==t[i])te++;
        }else if(d[i]=='R'){
            if(0<=ts && S[ts]==t[i])ts--;
            if(0<te && S[te-1]==t[i])te--;
        }
    }
    cout<<N-(ts+1+N-te)<<endl;
    return 0;
}
