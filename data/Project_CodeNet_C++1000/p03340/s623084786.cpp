#include <iostream>
#include <cassert>
#include <algorithm>
typedef long long ll;
#define MAXN (int(2e5))
using namespace std;

int main(int argc,char ** argv)
{
    int n;
    cin>>n;
    int a[MAXN];
    for(int i=0;i<n;++i)cin>>a[i];
    ll cache=0,ans=0;
    int r=0;
    for(int i=0;i<n;++i){
        while(r<n){
            if(cache+a[r]!=(cache^a[r]))
                break;
            cache+=a[r];
            ++r;
        }
        ans+=r-i;
        cache-=a[i];
    }
    cout<<ans<<endl;
    //system("pause > nul");
    return 0;
}