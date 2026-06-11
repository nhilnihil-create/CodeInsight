#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int ans=0;
    a.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        int tmp=1;
        while(a[i]==a[i+1]){
            tmp++;
            i++;
        }
        ans+=tmp/2;
    }
    cout<<ans<<endl;
}