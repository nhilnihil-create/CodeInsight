#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef vector<int> vi;
typedef long long ll;



int main(){
    ll N,A,B,ans;
    cin>>N>>A>>B;
    if(A+2>=B||N+1<=A){
        cout<<N+1<<endl;
        return 0;
    }
    else{
        N=N-A+1;
        ans=A+(B-A)*(N/2);
        if(N%2==1)ans++;
    }
    cout<<ans<<endl;
}




