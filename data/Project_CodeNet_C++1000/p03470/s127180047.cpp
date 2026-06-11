#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    int N;
    cin>>N;
    vector<int> vec(N);
    rep(i,N){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());

    int count=1;
    if(N==1) cout<<count<<endl;
    else
    {
        rep(i,N-1){
            if(vec[i+1]-vec[i]!=0) count++;
            else continue;
        }
        cout<<count<<endl;
    }
    

}