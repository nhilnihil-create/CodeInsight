#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    ll N,A,B;
    cin>>N>>A>>B;
    if(A*B<N || A+B>N+1) cout<<-1<<endl;
    else{
        if(B==1){
            rep(i,N) cout<<i+1<<" ";
            return 0;
        }
        ll num;
        ll hoge=0;
        rep(i,A) cout<<N-A+1+i<<" ";
        num=A;
        rep(j,(N-A)/(B-1)){
            hoge++;
            rep(i,B-1){
                if(num==N) break;
                cout<< hoge*(B-1)-i <<" ";
                num++;
            }
        }
        hoge=0;
        while(num<N){
            cout<<N-A-hoge<<" ";
            hoge++;
            num++;
        }
    }
    return 0;
}