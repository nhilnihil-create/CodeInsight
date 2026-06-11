#include <iostream>
#include <algorithm>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
using P = pair<int,int>;

int main()
{
    int N,M;
    cin>>N>>M;
    P r[100010];
    rep(i,M){
        int a,b;
        cin>>a>>b;
        r[i] = make_pair(b-1,a-1);
    }

    sort(r,r+M);

    int ans=1,min=0;
    for(int i=1;i<M;i++){
        if(r[min].first<=r[i].second){
            ans++;
            min=i;
        }
    }

    cout << ans << endl;

    return 0;
}